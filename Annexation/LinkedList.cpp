#include "LinkedList.h"
using namespace Annexation;

LinkedList::LinkedList() {
	_memoryIndex = -1;
	_firstIndex = -1;
	//_next = nullptr;
}

LinkedList::~LinkedList() {
	//_next = nullptr;
}

/*int LinkedList::acquire() {
	if (this->_next == nullptr) {
		std::exception e("Next node's aquistision failed.");
		throw e;
		return -1;
	}

	int indexToBeReturned = this->_next->_memoryIndex;
	LinkedListNode* temp = this->_next;
	this->_next = temp->_next;
	temp->_next = nullptr;
	return indexToBeReturned;
}*/

/*void LinkedList::insert(LinkedListNode nodes[], int limit, int id) {
	if (id > limit) {
		std::exception e("Requested id to be inserted exceeds limit.");
		throw e;
		return;
	}

	LinkedListNode* curListNode = this->_next;
	LinkedListNode* prevListNode = nullptr;
	while (curListNode != nullptr && id < curListNode->_memoryIndex)
	{
		prevListNode = curListNode;
		curListNode = curListNode->_next;
	}

	int nowIndex = (curListNode == nullptr ? -1 : curListNode->_memoryIndex);
	if (id < nowIndex)
	{
		prevListNode->_next = &nodes[id];
		nodes[id]._next = curListNode->_next;
	}
	else
	{
		std::exception e("Invalid id of node of linked list to be inserted.");
		throw e;
	}
}*/

/*void LinkedList::createList(LinkedListNode nodes[], int size) {
	for (int i = 0; i < size; ++i) {
		nodes[i]._memoryIndex = i;
		nodes[i]._next = (i == size - 1 ? nullptr : &nodes[i + 1]);
	}
	_next = &nodes[0];
}*/

/*void LinkedList::del(int limit, int id) {
	if (id > limit) {
		std::exception e("Requested id to be deleted exceeds limit.");
		throw e;
		return;
	}

	LinkedListNode* curListNode = this->_next;
	LinkedListNode* prevListNode = nullptr;
	while (curListNode != nullptr && id != curListNode->_memoryIndex)
	{
		prevListNode = curListNode;
		curListNode = curListNode->_next;
	}

	int nowIndex = (curListNode == nullptr ? -1 : curListNode->_memoryIndex);
	if (id == nowIndex)
	{
		prevListNode->_next = curListNode->_next;
		curListNode->_next = nullptr;
	}
	else
	{
		std::exception e("Invalid id of node of linked list to be destroyed.");
		throw e;
	}
}*/

/*int LinkedList::getIndex() const {
	if (_next == nullptr) {
		return _memoryIndex;
	}
	return _next->_memoryIndex;
}*/


INodeLinkedList::INodeLinkedList() {
	create();
	_firstIndex = _nodes[0]._memoryIndex;
}

INodeLinkedList::~INodeLinkedList() {

}

int INodeLinkedList::acquire() {
	if (this->_firstIndex == -1) {
		std::exception e("Next node's aquistision failed.");
		throw e;
		return -1;
	}

	int indexToBeReturned = this->_firstIndex;
	_firstIndex = _nodes[_firstIndex]._next;
	_nodes[indexToBeReturned]._next = -1;
	return indexToBeReturned;
}

void INodeLinkedList::insert(int id) {
	if (id > INODE_COUNT) {
		std::exception e("Requested id to be inserted exceeds limit.");
		throw e;
		return;
	}

	int nowIndex = _firstIndex;
	int prevIndex = -1;
	while (nowIndex != -1 && nowIndex < id) {
		prevIndex = nowIndex;
		nowIndex = _nodes[nowIndex]._next;
	}

	if (nowIndex > id || nowIndex == -1) {
		if (prevIndex == -1) {
			_firstIndex = id;
		}
		else {
			_nodes[prevIndex]._next = id;
			_nodes[id]._next = nowIndex;
		}
	}
	else {
		std::exception e("Invalid id of node of linked list to be inserted.");
		throw e;
	}
}

void INodeLinkedList::create() {
	for (int i = 0; i < INODE_COUNT; ++i) {
		_nodes[i]._memoryIndex = i;
		_nodes[i]._next = (i == INODE_COUNT - 1 ? -1 : i + 1);
	}
	_firstIndex = _nodes[0]._memoryIndex;
}

void INodeLinkedList::del(int id) {
	if (id > INODE_COUNT) {
		std::exception e("Requested id to be deleted exceeds limit.");
		throw e;
		return;
	}

	int nowIndex = _firstIndex;
	int prevIndex = -1;
	while (nowIndex != -1 && nowIndex != id) {
		prevIndex = nowIndex;
		nowIndex = _nodes[nowIndex]._next;
	}

	if (nowIndex == id) {
		if (prevIndex == -1) {
			_firstIndex = _nodes[nowIndex]._next;
		}
		else {
			_nodes[prevIndex]._next = _nodes[nowIndex]._next;
			_nodes[nowIndex]._next = -1;
		}
	}
	else {
		std::exception e("Invalid id of node of linked list to be destroyed.");
		throw e;
	}
}


BlockLinkedList::BlockLinkedList() {
	create();
	_firstIndex = _nodes[0]._memoryIndex;
}

BlockLinkedList::~BlockLinkedList() {

}

int BlockLinkedList::acquire() {
	if (this->_firstIndex == -1) {
		std::exception e("Next node's aquistision failed.");
		throw e;
		return -1;
	}

	int indexToBeReturned = this->_firstIndex;
	_firstIndex = _nodes[_firstIndex]._next;
	_nodes[indexToBeReturned]._next = -1;
	return indexToBeReturned;
}

void BlockLinkedList::insert(int id) {
	if (id > BLOCK_COUNT) {
		std::exception e("Requested id to be inserted exceeds limit.");
		throw e;
		return;
	}

	int nowIndex = _firstIndex;
	int prevIndex = -1;
	while (nowIndex != -1 && nowIndex < id) {
		prevIndex = nowIndex;
		nowIndex = _nodes[nowIndex]._next;
	}

	if (nowIndex > id || nowIndex == -1) {
		if (prevIndex == -1) {
			_firstIndex = id;
		}
		else {
			_nodes[prevIndex]._next = id;
			_nodes[id]._next = nowIndex;
		}
	}
	else {
		std::exception e("Invalid id of node of linked list to be inserted.");
		throw e;
	}
}

void BlockLinkedList::create() {
	for (int i = 0; i < INODE_COUNT; ++i) {
		_nodes[i]._memoryIndex = i;
		_nodes[i]._next = (i == INODE_COUNT - 1 ? -1 : i + 1);
	}
	_firstIndex = _nodes[0]._memoryIndex;
}

void BlockLinkedList::del(int id) {
	if (id > BLOCK_COUNT) {
		std::exception e("Requested id to be deleted exceeds limit.");
		throw e;
		return;
	}

	int nowIndex = _firstIndex;
	int prevIndex = -1;
	while (nowIndex != -1 && nowIndex != id) {
		prevIndex = nowIndex;
		nowIndex = _nodes[nowIndex]._next;
	}

	if (nowIndex == id) {
		if (prevIndex == -1) {
			_firstIndex = _nodes[nowIndex]._next;
		}
		else {
			_nodes[prevIndex]._next = _nodes[nowIndex]._next;
			_nodes[nowIndex]._next = -1;
		}
	}
	else {
		std::exception e("Invalid id of node of linked list to be destroyed.");
		throw e;
	}
}