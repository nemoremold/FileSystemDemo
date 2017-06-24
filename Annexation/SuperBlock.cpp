//
//  SuperBlock.cpp
//  Annexation
//
//  Created by Emoin Lam on 20/06/2017.
//  Copyright © 2017 Emoin Lam. All rights reserved.
//

#include "SuperBlock.h"
using namespace Annexation;

SuperBlock::SuperBlock() {
	_iNodeMap = INodeAnnexationMap();
	_blockMap = BlockAnnexationMap();
	_blockUsedCount = 0;
	_iNodeUsedCount = 0;
}

SuperBlock::~SuperBlock() {
}

void SuperBlock::initialize() {
	_iNodeMap = INodeAnnexationMap();
	_blockMap = BlockAnnexationMap();
	_blockUsedCount = 0;
	_iNodeUsedCount = 0;

	if (acquireNewINode() == BAD_MAPPING) {
		return;
	}
	if (acquireNewBlock() == BAD_MAPPING) {
		return;
	}
}

int SuperBlock::acquireNewINode() {
	int newINodeAcquired = _iNodeMap.acquire();
	if (newINodeAcquired != BAD_MAPPING) {
		++_iNodeUsedCount;
		return newINodeAcquired;
	}
	return newINodeAcquired;
}

int SuperBlock::acquireNewBlock() {
	int newBlockAcquired = _blockMap.acquire();
	if (newBlockAcquired != BAD_MAPPING) {
		++_blockUsedCount;
		return newBlockAcquired;
	}
	return newBlockAcquired;
}

bool SuperBlock::removeINode(int index) {
	if (_iNodeMap.insert(index)) {
		--_iNodeUsedCount;
		return true;
	}
	return false;
}

bool SuperBlock::removeBlock(int index) {
	if (_blockMap.insert(index)) {
		--_blockUsedCount;
		return true;
	}
	return false;
}

int SuperBlock::getINodeUsedCount() const {
	return _iNodeUsedCount;
}

int SuperBlock::getBlockUsedCount() const{
	return _blockUsedCount;
}