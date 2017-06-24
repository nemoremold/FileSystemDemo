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
	const char FILE_SYSTEM_IO_BUFFER_DELETE[] = "del AnnexationFileSystemBuffer.txt";

	class FileSystem {
	public:
		FileSystem();
		~FileSystem();

		System::String^ getPath() const {
			System::String^ deliverer = gcnew System::String(_path.c_str());
			return deliverer;
		}
		/*std::string getPath() const {
			return _path;
		}*/
		int getCurrentINodeIndex() const {
			return _currentINodeIndex;
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