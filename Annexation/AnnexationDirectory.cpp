//
//  AnnexationDirectory.cpp
//  Annexation
//
//  Created by Emoin Lam on 22/06/2017.
//  Copyright © 2017 Emoin Lam. All rights reserved.
//

#include "AnnexationDirectory.h"
using namespace Annexation;

AnnexationDirectory::AnnexationDirectory(std::string name, int index)
	: _name(name), _iNodeIndex(index) {
}

AnnexationDirectory::~AnnexationDirectory() {
}

std::string AnnexationDirectory::getNameOfDirectory() const {
	return _name;
}

int AnnexationDirectory::getINodeIndexOfDirectory() const {
	return _iNodeIndex;
}

void AnnexationDirectory::setNameOfDirectory(std::string name) {
	_name = name;
}

void AnnexationDirectory::setINodeIndexOfDirectory(int index) {
	_iNodeIndex = index;
}