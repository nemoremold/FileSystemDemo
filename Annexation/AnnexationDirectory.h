//
//  AnnexationDirectory.h
//  Annexation
//
//  Created by Emoin Lam on 20/06/2017.
//  Copyright © 2017 Emoin Lam. All rights reserved.
//

#ifndef __ANNEXATION_DIRECTORY_H__
#define __ANNEXATION_DIRECTORY_H__

#include <iostream>
#include <string>
#include "SuperBlock.h"

namespace Annexation {
#define NEW_INODE_INDEX -1
#define NEW_DIRECTORY_NAME "New Directory"

	class AnnexationDirectory {
	public:
		AnnexationDirectory(std::string name = NEW_DIRECTORY_NAME, int index = NEW_INODE_INDEX);
		~AnnexationDirectory();

		std::string getNameOfDirectory() const;
		int getINodeIndexOfDirectory() const;
		void setNameOfDirectory(std::string name);
		void setINodeIndexOfDirectory(int index);

	private:
		std::string _name;
		int _iNodeIndex;
	};
}

#endif