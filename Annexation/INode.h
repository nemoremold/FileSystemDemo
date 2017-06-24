//
//  INode.h
//  Annexation
//
//  Created by Emoin Lam on 20/06/2017.
//  Copyright © 2017 Emoin Lam. All rights reserved.
//
#pragma once
#ifndef __INODE_H__
#define __INODE_H__

#include <iostream>

namespace Annexation {
#ifndef BLOCK_COUNT
#define BLOCK_COUNT 1024
#endif
#define BLOCK_SIZE 1024
#define BAD_MAPPING -1
#define MAX_FILE_SIZE BLOCK_COUNT * BLOCK_SIZE

	enum FileType {
		DIRECTORY,
		FILE,
		NONE
	};

	class INode {
	public:
		INode();
		~INode();

		void setBlockIdentifier(int id, int val);
		void resetBlockCount();
		bool removeABlock();
		bool setFileSize(int size);
		bool reduceFileSizeByAmount(int size);
		bool increaseFileSizeByAmount(int size);
		void setFileType(FileType type);
		int getBlockCount() const;
		int getBlockIdentifierOfId(int id) const;
		int getFileSize() const;
		FileType getFileType() const;

	private:
		int _blockIdentifier[BLOCK_COUNT];
		int _blockCount;
		int _fileSize;
		FileType _fileType;
	};
}

#endif