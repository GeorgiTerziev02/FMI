#pragma once
#include <iostream>

/// <summary>
/// Memory efficient linked lists
/// Keeps the previous Node address and the next Node
/// XOR-ed in the xnode property
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class XORLinkedList {
private:
	struct Node {
		T value;
		Node* xnode;

		Node(const T& value) : value(value), xnode(nullptr) {}
	};

	static Node* xorNext(Node* prev, Node* xnode);
	Node* head = nullptr;

	void forEach(void (*callback)(const Node*)) const;
	void forEach(void (*callback)(Node*));

public:
	XORLinkedList() = default;
	XORLinkedList(const XORLinkedList&) = delete;
	XORLinkedList& operator=(const XORLinkedList&) = delete;
	~XORLinkedList();

	void push_back(const T& value);
	void print() const;
};

template<typename T>
typename XORLinkedList<T>::Node* XORLinkedList<T>::xorNext(Node* prev, Node* xnode) {
	return (XORLinkedList::Node*)((uintptr_t)prev ^ (uintptr_t)xnode);
}

template<typename T>
XORLinkedList<T>::~XORLinkedList() {
	forEach([](Node* node) { delete node; });
}

template<typename T>
void XORLinkedList<T>::push_back(const T& value) {
	if (!head) {
		head = new Node(value);
		return;
	}

	Node* prev = nullptr;
	Node* current = head;
	while (current) {
		Node* temp = current;
		current = xorNext(prev, current->xnode);
		prev = temp;
	}

	Node* newNode = new Node(value);
	newNode->xnode = prev;
	prev->xnode = xorNext(prev->xnode, newNode);
}

template<typename T>
void XORLinkedList<T>::print() const {
	forEach([](const Node* node) { std::cout << node->value << std::endl; });
}

template<typename T>
void XORLinkedList<T>::forEach(void (*callback)(Node*)) {
	Node* prev = nullptr;
	Node* current = head;
	while (current) {
		Node* temp = current;
		current = xorNext(prev, current->xnode);
		prev = temp;
		callback(temp);
	}
}

template<typename T>
void XORLinkedList<T>::forEach(void (*callback)(const Node*)) const {
	Node* prev = nullptr;
	Node* current = head;
	while (current) {
		Node* temp = current;
		current = xorNext(prev, current->xnode);
		prev = temp;
		callback(temp);
	}
}

// Test
//#include "XORLinkedList.hpp"
//
//#define _CRTDBG_MAP_ALLOC
//#include <cstdlib>
//#include <crtdbg.h>
//
//#ifdef _DEBUG
//#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//#endif
//
//int main()
//{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	XORLinkedList<int> xll;
//	xll.push_back(1);
//	xll.push_back(2);
//	xll.push_back(3);
//	xll.push_back(4);
//	xll.print();
//}