//
//  AnnexationMapping.h
//  Annexation
//
//  Created by Emoin Lam on 22/06/2017.
//  Copyright © 2017 Emoin Lam. All rights reserved.
//

#ifndef __ANNEXATION_MAPPING_H__
#define __ANNEXATION_MAPPING_H__

#include <iostream>

namespace Annexation {
#define INODE_COUNT 1024
#define BLOCK_COUNT 80 * 1024
#define BAD_MAPPING -1

	class INodeAnnexationMap {
	public:
		INodeAnnexationMap();
		~INodeAnnexationMap();

		int acquire();
		bool insert(int index);

	private:
		bool _map[INODE_COUNT];
	};

	class BlockAnnexationMap {
	public:
		BlockAnnexationMap();
		~BlockAnnexationMap();

		int acquire();
		bool insert(int index);

	private:
		bool _map[INODE_COUNT];
	};
}

#endif