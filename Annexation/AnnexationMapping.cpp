//
//  AnnexationMapping.cpp
//  Annexation
//
//  Created by Emoin Lam on 22/06/2017.
//  Copyright © 2017 Emoin Lam. All rights reserved.
//

#include "AnnexationMapping.h"
using namespace Annexation;

INodeAnnexationMap::INodeAnnexationMap() {
	for (int i = 0; i < INODE_COUNT; ++i) {
		_map[i] = true;
	}
}

INodeAnnexationMap::~INodeAnnexationMap() {
}

int INodeAnnexationMap::acquire() {
	for (int i = 0; i < INODE_COUNT; ++i) {
		if (_map[i]) {
			_map[i] = false;
			return i;
		}
	}

	std::exception e("INodeAnnexationMap: Bad mapping.");
	throw e;
	return BAD_MAPPING;
}

bool INodeAnnexationMap::insert(int index) {
	if (_map[index]) {
		std::exception e("INodeAnnexationMap: Bad insertion.");
		throw e;
	}
	else {
		_map[index] = true;
		return true;
	}
	return false;
}

BlockAnnexationMap::BlockAnnexationMap() {
	for (int i = 0; i < INODE_COUNT; ++i) {
		_map[i] = true;
	}
}

BlockAnnexationMap::~BlockAnnexationMap() {
}

int BlockAnnexationMap::acquire() {
	for (int i = 0; i < INODE_COUNT; ++i) {
		if (_map[i]) {
			_map[i] = false;
			return i;
		}
	}

	std::exception e("BlockAnnexationMap: Bad mapping.");
	throw e;
	return BAD_MAPPING;
}

bool BlockAnnexationMap::insert(int index) {
	if (_map[index]) {
		std::exception e("BlockAnnexationMap: Bad insertion.");
		throw e;
	}
	else {
		_map[index] = true;
		return true;
	}
	return false;
}