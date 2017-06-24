//
//  INode.cpp
//  Annexation
//
//  Created by Emoin Lam on 22/06/2017.
//  Copyright © 2017 Emoin Lam. All rights reserved.
//

#include "INode.h"
using namespace Annexation;

INode::INode() {
	for (int i = 0; i < BLOCK_COUNT; ++i) {
		_blockIdentifier[i] = BAD_MAPPING;
	}
	_blockCount = 0;
	_fileSize = 0;
	_fileType = NONE;
}

INode::~INode() {
}

void INode::setBlockIdentifier(int id, int val) {
	_blockIdentifier[id] = val;
	++_blockCount;
}

void INode::resetBlockCount() {
	_blockCount = 0;
}

bool INode::removeABlock() {
	if (_blockCount == 0) {
		std::exception e("INode: can't remove a block: too few blocks");
		throw e;
		return false;
	}

	--_blockCount;
	return true;
}

bool INode::setFileSize(int size) {
	if (size > MAX_FILE_SIZE) {
		std::exception e("INode: size too large to set.");
		throw e;
		return false;
	}

	_fileSize = size;
	return true;
}

bool INode::reduceFileSizeByAmount(int size) {
	if (size > _fileSize) {
		std::exception e("INode: size too large to decrease.");
		throw e;
		return false;
	}

	_fileSize -= size;
	return true;
}

bool INode::increaseFileSizeByAmount(int size) {
	if (size + _fileSize > MAX_FILE_SIZE) {
		std::exception e("INode: size too large to increase.");
		throw e;
		return false;
	}

	_fileSize += size;
	return true;
}

void INode::setFileType(FileType type) {
	_fileType = type;
}

int INode::getBlockCount() const {
	return _blockCount;
}

int INode::getBlockIdentifierOfId(int id) const {
	if (id >= 0 && id < BLOCK_SIZE) {
		return _blockIdentifier[id];
	}
	else {
		std::exception e("INode: Invalid id of block identifier.");
		throw e;
		return -1;
	}
}

int INode::getFileSize() const {
	return _fileSize;
}

FileType INode::getFileType() const {
	return _fileType;
}