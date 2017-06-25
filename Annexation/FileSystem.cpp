//
//  FileSystem.cpp
//  Annexation
//
//  Created by Emoin Lam on 20/06/2017.
//  Copyright © 2017 Emoin Lam. All rights reserved.
//

#include "FileSystem.h"
using namespace Annexation;

FileSystem::FileSystem() {
	_path = FILE_SYSTEM_ROOT_PATH;
	fopen_s(&_systemDisk, FILE_SYSTEM_DISK_PATH, "r+");
	_directory = new AnnexationDirectory[DIRECTORY_COUNT];
	_superBlock = new SuperBlock;
	_currentINode = new INode;
	if (_systemDisk == nullptr) {
		std::exception e("FileSystem: unable to launch file system disk.");
		throw e;
	}
	FILE_DEL = nullptr;
	FILE_PATH = nullptr;
}

FileSystem::~FileSystem() {
	if (_systemDisk != nullptr) {
		fclose(_systemDisk);
	}
	delete [] _directory;
	delete _currentINode;
	delete _superBlock;
	_systemDisk = nullptr;
}

bool FileSystem::initializeFileSystem() {
	fseek(_systemDisk, SUPER_BLOCK_BEGIN_INDEX_IN_MEMORY, SEEK_SET);
	fread(_superBlock, sizeof(SuperBlock), 1, _systemDisk);
	
	_currentINodeIndex = ROOT_NODE_INDEX;
	if (!openDirectory(_currentINodeIndex)) {
		std::exception e("FileSystem: unable to initialize root directory.");
		throw e;
		return false;
	}
	return true;
}

void FileSystem::exitFileSystem() {
	int check = fseek(_systemDisk, SUPER_BLOCK_BEGIN_INDEX_IN_MEMORY, SEEK_SET);
	fwrite(_superBlock, sizeof(SuperBlock), 1, _systemDisk);

	closeDirectory(_currentINodeIndex);
}

bool FileSystem::openDirectory(int index) {
	int check = 0;
	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * index, SEEK_SET);
	check = fread(_currentINode, sizeof(INode), 1, _systemDisk);
	
	int directoryPosition = 0;
	int blockCount = _currentINode->getBlockCount();
	for (int i = 0; i < blockCount - 1; ++i) {
		fseek(_systemDisk, BLOCK_BEGIN_INDEX_IN_MEMORY + BLOCK_SIZE * _currentINode->getBlockIdentifierOfId(i), SEEK_SET);
		check = fread(_directory + directoryPosition, sizeof(AnnexationDirectory), DIRECTORY_PER_BLOCK, _systemDisk);
		directoryPosition += DIRECTORY_PER_BLOCK;
	}

	int directoryLeft = _currentINode->getFileSize() / sizeof(AnnexationDirectory) - DIRECTORY_PER_BLOCK * (blockCount - 1);
	fseek(_systemDisk, BLOCK_BEGIN_INDEX_IN_MEMORY + BLOCK_SIZE * _currentINode->getBlockIdentifierOfId(blockCount - 1), SEEK_SET);
	check = fread(_directory + directoryPosition, sizeof(AnnexationDirectory), directoryLeft, _systemDisk);
	directoryPosition += directoryLeft;
	
	_directoryCount = directoryPosition;
	if (check == 0) {
		return false;
	}
	return true;
}

void FileSystem::closeDirectory(int index) {
	int directoryPosition = 0;
	int blockCount = _currentINode->getBlockCount();
	for (int i = 0; i < blockCount - 1; ++i) {
		fseek(_systemDisk, BLOCK_BEGIN_INDEX_IN_MEMORY + BLOCK_SIZE * _currentINode->getBlockIdentifierOfId(i), SEEK_SET);
		fwrite(_directory + directoryPosition, sizeof(AnnexationDirectory), DIRECTORY_PER_BLOCK, _systemDisk);
		directoryPosition += DIRECTORY_PER_BLOCK;
	}
	
	int directoryLeft = _directoryCount - directoryPosition;
	fseek(_systemDisk, BLOCK_BEGIN_INDEX_IN_MEMORY + BLOCK_SIZE * _currentINode->getBlockIdentifierOfId(blockCount - 1), SEEK_SET);
	fwrite(_directory + directoryPosition, sizeof(AnnexationDirectory), directoryLeft, _systemDisk);

	_currentINode->setFileSize(_directoryCount * sizeof(AnnexationDirectory));
	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * index, SEEK_SET);
	fwrite(_currentINode, sizeof(INode), 1, _systemDisk);
}

void FileSystem::formatFileSystem() {
	_superBlock->initialize();
	_currentINodeIndex = 0;

	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY, SEEK_SET);
	fread(_currentINode, sizeof(INode), 1, _systemDisk);

	_currentINode->resetBlockCount();
	_currentINode->setFileSize(sizeof(AnnexationDirectory) << 1);
	_currentINode->setFileType(DIRECTORY);
	_currentINode->setBlockIdentifier(0, 0);

	_directoryCount = 0;
	setDirectory(".", 0);
	setDirectory("..", 0);

	setPath(FILE_SYSTEM_ROOT_PATH);

	exitFileSystem();
	initializeFileSystem();
}

void FileSystem::setDirectory(std::string name, int iNodeIndex) {
	_directory[_directoryCount].setNameOfDirectory(name);
	_directory[_directoryCount++].setINodeIndexOfDirectory(iNodeIndex);
}

void FileSystem::setPath(std::string path) {
	_path = path;
}

bool FileSystem::makeFile(int index, std::string name, FileType type) {
	int blockNeeded = 1;

	if (_directoryCount >= DIRECTORY_COUNT) {
		std::exception e("FileSystem: can not create new directories: directory full.");
		throw e;
		return false;
	}
	if (getInodeIndexOfName(name) != BAD_MAPPING) {
		std::string report = "FileSystem: " + name + " already exists.";
		char* report2 = new char[report.length()];
		for (int i = 0; i < report.length(); ++i) {
			report2[i] = report[i];
		}
		std::exception e(report2);
		throw e;
		return false;
	}
	if (_directoryCount / DIRECTORY_PER_BLOCK != (_directoryCount + 1) / DIRECTORY_PER_BLOCK) {
		blockNeeded = 2;
	}

	if (_superBlock->getBlockUsedCount() + blockNeeded > BLOCK_COUNT) {
		std::exception e("FileSystem: no block available.");
		throw e;
		return false;
	}
	if (blockNeeded == 2) {
		_currentINode->setBlockIdentifier(_currentINode->getBlockCount(), _superBlock->acquireNewBlock());
	}

	int newINodeIndex = _superBlock->acquireNewINode();
	if (newINodeIndex == BAD_MAPPING) {
		std::exception e("FileSystem: no iNode available.");
		throw e;
		return false;
	}

	if (type == DIRECTORY) {
		createNewDirectoryINode(newINodeIndex, index);
	}
	else if (type == FILE) {
		createNewFileINode(newINodeIndex);
	}
	else {
		std::exception e("FileSystem: invalid FileType.");
		throw e;
		return false;
	}

	setDirectory(name, newINodeIndex);
	enterDirectory(index, ".");
	recalculateFileSize();
	return true;
}

int FileSystem::getInodeIndexOfName(std::string name) const {
	for (int i = 0; i < _directoryCount; ++i) {
		if (_directory[i].getNameOfDirectory() == name) {
			return _directory[i].getINodeIndexOfDirectory();
		}
	}
	return -1;
}

void FileSystem::createNewDirectoryINode(int branch, int root) {
	INode* temp = new INode;
	int blockPosition;

	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * branch, SEEK_SET);
	fread(temp, sizeof(INode), 1, _systemDisk);

	blockPosition = _superBlock->acquireNewBlock();
	temp->resetBlockCount();
	temp->setBlockIdentifier(temp->getBlockCount(), blockPosition);
	temp->setFileType(DIRECTORY);
	temp->setFileSize(sizeof(AnnexationDirectory) << 1);
	_currentINode->increaseFileSizeByAmount(sizeof(AnnexationDirectory) << 1);

	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * branch, SEEK_SET);
	fwrite(temp, sizeof(INode), 1, _systemDisk);

	AnnexationDirectory tempDirectory[2];
	tempDirectory[0] = AnnexationDirectory(".", branch);
	tempDirectory[1] = AnnexationDirectory("..", root);

	fseek(_systemDisk, BLOCK_BEGIN_INDEX_IN_MEMORY + BLOCK_SIZE * blockPosition, SEEK_SET);
	fwrite(tempDirectory, sizeof(AnnexationDirectory), 2, _systemDisk);}

void FileSystem::createNewFileINode(int branch) {
	INode* temp = new INode;

	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * branch, SEEK_SET);
	fread(temp, sizeof(INode), 1, _systemDisk);

	temp->resetBlockCount();
	temp->setFileType(FILE);
	temp->setFileSize(0);

	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * branch, SEEK_SET);
	fwrite(temp, sizeof(INode), 1, _systemDisk);
}

void FileSystem::showDirectory() {
	recalculateFileSize();
	std::cout << std::right << std::setw(20) << "Name"
		<< std::setw(20) << "Address"
		<< std::setw(20) << "Size"
		<< std::setw(20) << "Type"
		<< std::endl;
	for (int i = 0; i < _directoryCount; ++i) {
		int iNodeIndex = getInodeIndexOfName(_directory[i].getNameOfDirectory());
		INode* temp = new INode;

		fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * iNodeIndex, SEEK_SET);
		fread(temp, sizeof(INode), 1, _systemDisk);

		if (temp->getFileType() != NONE) {
			std::cout << std::right << std::setw(20) << _directory[i].getNameOfDirectory()
				<< std::setw(20) << INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * iNodeIndex
				<< std::setw(20) << temp->getFileSize()
				<< std::setw(20) << (temp->getFileType() == DIRECTORY ? "DIRECTORY" : "FILE")
				<< std::endl;
		}
		/*else {
			std::exception e("FIleSystem: bad FileType.");
			throw e;
		}*/
	}
	std::cout << "Total file size: " << _currentINode->getFileSize() << std::endl;
}

bool FileSystem::enterDirectory(int root, std::string name) {
	int branch = getInodeIndexOfName(name);

	if (branch == BAD_MAPPING) {
		std::string report = "FileSystem: " + name + "does not exist.";
		char* report2 = new char[report.length()];
		for (int i = 0; i < report.length(); ++i) {
			report2[i] = report[i];
		}
		std::exception e(report2);
		throw e;
	}
	else {
		recalculateFileSize();
		closeDirectory(root);
		_currentINodeIndex = branch;
		if (openDirectory(branch)) {
			recalculateFileSize();
			return true;
		}
		else {
			_currentINodeIndex = root;
			openDirectory(root);
		}
	}
	return false;
}

bool FileSystem::removeFile(FileType type, int index, std::string name, int depth) {
	if (name == "." || name == "..") {
		std::string report = "FileSystem: unable to remove " + name + ": system file.";
		char* report2 = new char[report.length()];
		for (int i = 0; i < report.length(); ++i) {
			report2[i] = report[i];
		}
		std::exception e(report2);
		throw e;
		return false;
	}

	int branch = getInodeIndexOfName(name);

	if (branch == BAD_MAPPING) {
		std::string report = "FileSystem: " + name + " does not exist.";
		char* report2 = new char[report.length()];
		for (int i = 0; i < report.length(); ++i) {
			report2[i] = report[i];
		}
		std::exception e(report2);
		throw e;
		return false;
	}

	INode* temp = new INode;

	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * branch, SEEK_SET);
	fread(temp, sizeof(INode), 1, _systemDisk);

	if (temp->getFileType() == FILE) {
		if (type == DIRECTORY) {
			std::string report = "FileSystem: " + name + " is not a file.";
			char* report2 = new char[report.length()];
			for (int i = 0; i < report.length(); ++i) {
				report2[i] = report[i];
			}
			std::exception e(report2);
			throw e;
			return false;
		}

		_superBlock->_currentDiskSize -= temp->getFileSize();
		if (removeINode(branch)) {
			if (depth == 0) {
				adjustDirectory(name);
			}
			return true;
		}
	}
	else if (temp->getFileType() == DIRECTORY) {
		if (type == FILE) {
			std::string report = "FileSystem: " + name + " is not a directory.";
			char* report2 = new char[report.length()];
			for (int i = 0; i < report.length(); ++i) {
				report2[i] = report[i];
			}
			std::exception e(report2);
			throw e;
			return false;
		}

		if (!enterDirectory(index, name)) {
			return false;
		}
		for (int i = 2; i < _directoryCount; ++i) {
			int iNodeIndex = _directory[i].getINodeIndexOfDirectory();
			INode* temp2 = new INode;
			fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * iNodeIndex, SEEK_SET);
			fread(temp2, sizeof(INode), 1, _systemDisk);
			if (!removeFile(temp2->getFileType(), branch, _directory[i].getNameOfDirectory(), depth + 1)) {
				return false;
			}
		}
		enterDirectory(branch, "..");
		if (removeINode(branch)) {
			if (depth == 0) {
				if (_directoryCount / DIRECTORY_PER_BLOCK != (_directoryCount - 1) / DIRECTORY_PER_BLOCK) {
					if (!_currentINode->removeABlock()) {
						return false;
					}
					if (!removeBlock(_currentINode->getBlockCount())) {
						return false;
					}
				}
				adjustDirectory(name);
			}
			return true;
		}
	}
	else {
		std::exception e("FileSystem: invalid FileType.");
		throw e;
		return false;
	}
	return false;
}

bool FileSystem::removeINode(int branch) {
	INode* temp = new INode;

	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * branch, SEEK_SET);
	fread(temp, sizeof(INode), 1, _systemDisk);

	int blockCount = temp->getBlockCount();
	for (int i = 0; i < blockCount; ++i) {
		if (!removeBlock(temp->getBlockIdentifierOfId(i))) {
			return false;
		}
	}
	_superBlock->removeINode(branch);
	return true;
}

bool FileSystem::removeBlock(int index) {
	if (_superBlock->removeBlock(index)) {
		return true;
	}
	return false;
}

void FileSystem::adjustDirectory(std::string name) {
	int position;
	for (position = 0; position < _directoryCount; ++position) {
		if (_directory[position].getNameOfDirectory() == name) {
			break;
		}
	}
	for (++position; position < _directoryCount; ++position) {
		_directory[position - 1] = _directory[position];
	}
	--_directoryCount;
}

void FileSystem::changePath(std::string path) {
	std::string newPath;
	if (path == ".") {
		return;
	}
	else if (path == "..") {
		int record = -1;
		for (int i = _path.length() - 2; i >= 0; --i) {
			if (_path[i] == '\\') {
				record = i;
				break;
			}
		}
		for (int j = 0; j <= record; ++j) {
			newPath += _path[j];
		}
		if (record != -1) {
			_path = newPath;
		}
	}
	else {
		_path += (path + "\\");
	}
}

void FileSystem::readFile(std::string name) {
	INode* temp = new INode;
	std::FILE* buffer;
	char charBuffer[BLOCK_SIZE];
	int index;

	std::string bufferPath = name + FILE_SYSTEM_IO_BUFFER_PATH;
	char* bufferred = new char[bufferPath.length() + 1];
	int cnt = 0;
	for (int i = 0; i < bufferPath.length(); ++i) {
		if (bufferPath[i] != ' ') {
			bufferred[cnt++] = bufferPath[i];
		}
	}
	bufferred[cnt] = '\0';

	//fopen_s(&buffer, FILE_SYSTEM_IO_BUFFER_PATH, "w+");
	fopen_s(&buffer, FILE_PATH, "w+");
	index = getInodeIndexOfName(name);

	delete bufferred;
	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * index, SEEK_SET);
	fread(temp, sizeof(INode), 1, _systemDisk);

	if (temp->getBlockCount() == 0) {
		fclose(buffer);
		return;
	}

	_superBlock->_currentDiskSize -= temp->getFileSize();

	int blockCount = temp->getBlockCount();
	int blockIndex;
	for (int i = 0; i < blockCount - 1; ++i) {
		blockIndex = temp->getBlockIdentifierOfId(i);

		fseek(_systemDisk, BLOCK_BEGIN_INDEX_IN_MEMORY + BLOCK_SIZE * blockIndex, SEEK_SET);
		fread(charBuffer, sizeof(char), BLOCK_SIZE, _systemDisk);
		fwrite(charBuffer, sizeof(char), BLOCK_SIZE, buffer);

		removeBlock(blockIndex);
		temp->reduceFileSizeByAmount(BLOCK_SIZE);
		temp->removeABlock();
	}

	blockIndex = temp->getBlockIdentifierOfId(blockCount - 1);

	fseek(_systemDisk, BLOCK_BEGIN_INDEX_IN_MEMORY + BLOCK_SIZE * blockIndex, SEEK_SET);
	fread(charBuffer, sizeof(char), temp->getFileSize(), _systemDisk);
	fwrite(charBuffer, sizeof(char), temp->getFileSize(), buffer);

	removeBlock(blockIndex);
	temp->setFileSize(0);
	temp->removeABlock();

	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * index, SEEK_SET);
	fwrite(temp, sizeof(INode), 1, _systemDisk);

	fclose(buffer);
}

void FileSystem::writeFile(std::string name) {
	INode* temp = new INode;
	std::FILE* buffer;
	char charBuffer[BLOCK_SIZE];
	int index;

	std::string bufferPath = name + FILE_SYSTEM_IO_BUFFER_PATH;
	char* bufferred = new char[bufferPath.length() + 1];
	int cnt = 0;
	for (int i = 0; i < bufferPath.length(); ++i) {
		if (bufferPath[i] != ' ') {
			bufferred[cnt++] = bufferPath[i];
		}
	}
	bufferred[cnt] = '\0';

	//fopen_s(&buffer, FILE_SYSTEM_IO_BUFFER_PATH, "r");
	fopen_s(&buffer, FILE_PATH, "r");
	index = getInodeIndexOfName(name);

	delete bufferred;
	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * index, SEEK_SET);
	fread(temp, sizeof(INode), 1, _systemDisk);

	temp->setFileSize(0);
	int blockIndex;
	int fileSize = 0;
	while (fileSize = fread(charBuffer, sizeof(char), BLOCK_SIZE, buffer)) {
		blockIndex = _superBlock->acquireNewBlock();
		if (blockIndex == -1) {
			std::exception e("FileSystem: blocks have been used up.");
			throw e;
			break;
		}

		temp->setBlockIdentifier(temp->getBlockCount(), blockIndex);
		temp->increaseFileSizeByAmount(fileSize);
		_superBlock->_currentDiskSize += fileSize;

		fseek(_systemDisk, BLOCK_BEGIN_INDEX_IN_MEMORY + BLOCK_SIZE * blockIndex, SEEK_SET);
		fwrite(charBuffer, sizeof(char), fileSize, _systemDisk);
	}

	fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * index, SEEK_SET);
	fwrite(temp, sizeof(INode), 1, _systemDisk);

	recalculateFileSize();
	fclose(buffer);
}

void FileSystem::recalculateFileSize() {
	_currentINode->setFileSize(sizeof(AnnexationDirectory) << 1);
	for (int i = 2; i < _directoryCount; ++i) {
		//int iNodeIndex = getInodeIndexOfName(_directory[i].getNameOfDirectory());
		int iNodeIndex = _directory[i].getINodeIndexOfDirectory();
		INode* temp = new INode;

		fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * iNodeIndex, SEEK_SET);
		fread(temp, sizeof(INode), 1, _systemDisk);

		_currentINode->increaseFileSizeByAmount(temp->getFileSize());
	}
}