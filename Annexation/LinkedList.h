#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include <typeinfo>
#include <exception>

namespace Annexation {
#define INODE_COUNT 1024
#define BLOCK_COUNT 80 * 1024

	enum ListNodeType {
		ROOT,
		BRANCH
	};


	struct LinkedListNode {
		int _memoryIndex;
		int _next;
	};


	class LinkedList {
	public:
		LinkedList();
		~LinkedList();

		//virtual int acquire();
		//virtual void insert(LinkedListNode nodes[], int limit, int id);

	protected:
		int _memoryIndex;
		int _firstIndex;
		//LinkedListNode* _next;

		//virtual void createList(LinkedListNode nodes[], int size);
		//virtual void del(int limit, int id);
		//int getIndex() const;
	};


	class INodeLinkedList : LinkedList {
	public:
		INodeLinkedList();
		~INodeLinkedList();

		int acquire();
		void insert(int id);

	private:
		LinkedListNode _nodes[INODE_COUNT];

		void create();
		void del(int id);
	};


	class BlockLinkedList : LinkedList {
	public:
		BlockLinkedList();
		~BlockLinkedList();

		int acquire();
		void insert(int id);

	private:
		LinkedListNode _nodes[BLOCK_COUNT];

		void create();
		void del(int id);
	};
}

#endif