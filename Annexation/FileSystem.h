//
//  FileSystem.h
//  Annexation
//
//  Created by Emoin Lam on 20/06/2017.
//  Copyright © 2017 Emoin Lam. All rights reserved.
//

#ifndef __FILE_SYSTEM_H__
#define __FILE_SYSTEM_H__

#include <string>
#include <fstream>
#include <iomanip>
#include "SuperBlock.h"
#include "INode.h"
#include "AnnexationDirectory.h"

namespace Annexation {
#define INODE_COUNT 1024
#define BLOCK_PER_NODE 1024
#ifndef BLOCK_COUNT
#define BLOCK_COUNT 80 * 1024
#endif
#define BLOCK_SIZE 1024
#define DIRECTORY_PER_BLOCK BLOCK_SIZE / sizeof(AnnexationDirectory)
#define DIRECTORY_COUNT BLOCK_PER_NODE * BLOCK_SIZE / sizeof(AnnexationDirectory)
#define SUPER_BLOCK_BEGIN_INDEX_IN_MEMORY 0
#define INODE_BEGIN_INDEX_IN_MEMORY sizeof(SuperBlock)
#define BLOCK_BEGIN_INDEX_IN_MEMORY INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * INODE_COUNT
#define ROOT_NODE_INDEX 0
#define FILE_SYSTEM_COMMAND_COUNT 9

	const std::string FILE_SYSTEM_ROOT_PATH = "Annexe:\\";
	const std::string FILE_SYSTEM_COMMAND[FILE_SYSTEM_COMMAND_COUNT]
		= { "fmt", "quit", "mkdir", "rmdir", "cd", "ls", "mk", "rm", "vim" };
	const char FILE_SYSTEM_DISK_PATH[] = "AnnexationFileSystemDisk.dat";
	const char FILE_SYSTEM_IO_BUFFER_PATH[] = "AnnexationFileSystemBuffer.txt";
	//const std::string FILE_SYSTEM_IO_BUFFER_PATH = "AFSBuffer.txt";
	const char FILE_SYSTEM_IO_BUFFER_DELETE[] = "del AnnexationFileSystemBuffer.txt";

	class FileSystem {
	public:
		FileSystem();
		~FileSystem();

		System::String^ getPath() const {
			System::String^ deliverer = gcnew System::String(_path.c_str());
			return deliverer;
		}
		std::string getPathInString() const {
			return _path;
		}
		int getCurrentINodeIndex() const {
			return _currentINodeIndex;
		}
		int getCurrentDiskSize() {
			/*INode* calculateSize = new INode;
			fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * root, SEEK_SET);
			fread(calculateSize, sizeof(INode), 1, _systemDisk);*/

			return _superBlock->_currentDiskSize;
		}
		System::String^ Parse(int value) const {
			std::ofstream temp;
			temp.open("Parser.txt");
			temp << value;
			temp.close();
			std::ifstream temp2;
			std::string parser;
			temp2.open("Parser.txt");
			temp2 >> parser;
			System::String^ deliverer = gcnew System::String(parser.c_str());
			return deliverer;
		}
		bool checkNameExistance(std::string name) {
			if (getInodeIndexOfName(name) != BAD_MAPPING) {
				return false;
			}
			return true;
		}
		int getFileCount() const {
			return _directoryCount;
		}
		void setNameOfDirectoryId(int id, std::string name) {
			_directory[id].setNameOfDirectory(name);
		}
		System::String^ getNameOfDirectoryId(int id) const {
			System::String^ deliverer = gcnew System::String(_directory[id].getNameOfDirectory().c_str());
			return deliverer;
		}
		std::string getNameOfDirectoryIdInString(int id) const {
			return _directory[id].getNameOfDirectory();
		}
		System::String^ getFileTypeOfDirectoryId(int id) {
			INode* temp = new INode;
			int index = _directory[id].getINodeIndexOfDirectory();
			fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * index, SEEK_SET);
			fread(temp, sizeof(INode), 1, _systemDisk);

			std::string cur = (temp->getFileType() == FILE ? "FILE" : "DIRECTORY");
			System::String^ deliverer = gcnew System::String(cur.c_str());
			return deliverer;
		}
		int getFileSizeOfDirectoryId(int id) {
			INode* temp = new INode;
			int index = _directory[id].getINodeIndexOfDirectory();
			fseek(_systemDisk, INODE_BEGIN_INDEX_IN_MEMORY + sizeof(INode) * index, SEEK_SET);
			fread(temp, sizeof(INode), 1, _systemDisk);
			return temp->getFileSize();
		}

		bool initializeFileSystem();
		void formatFileSystem();
		void exitFileSystem();
		bool makeFile(int index, std::string name, FileType type);
		bool removeFile(FileType type, int index, std::string name, int depth);
		bool enterDirectory(int root, std::string name);
		void changePath(std::string path);
		void showDirectory();
		void readFile(std::string name);
		void writeFile(std::string name);

	private:
		std::string _path;
		std::FILE* _systemDisk;
		SuperBlock* _superBlock;
		INode* _currentINode;
		AnnexationDirectory* _directory;
		int _currentINodeIndex;
		int _directoryCount;

		bool openDirectory(int index);
		void closeDirectory(int index);
		void setDirectory(std::string name, int iNodeIndex);
		void setPath(std::string path);
		int getInodeIndexOfName(std::string name) const;
		void createNewDirectoryINode(int branch, int root);
		void createNewFileINode(int branch);
		bool removeINode(int index);
		bool removeBlock(int index);
		void adjustDirectory(std::string name);
		void recalculateFileSize();
	};
}

#endif