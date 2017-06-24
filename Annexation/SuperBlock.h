//
//  SuperBlock.h
//  Annexation
//
//  Created by Emoin Lam on 20/06/2017.
//  Copyright © 2017 Emoin Lam. All rights reserved.
//

#ifndef __SUPER_BLOCK_H__
#define __SUPER_BLOCK_H__

#include "AnnexationMapping.h"

namespace Annexation {

	class SuperBlock {
	public:
		SuperBlock();
		~SuperBlock();

		void initialize();
		int acquireNewINode();
		int acquireNewBlock();
		bool removeINode(int index);
		bool removeBlock(int index);
		int getINodeUsedCount() const;
		int getBlockUsedCount() const;

	private:
		INodeAnnexationMap _iNodeMap;
		BlockAnnexationMap _blockMap;

		int _iNodeUsedCount;
		int _blockUsedCount;
	};
}

#endif