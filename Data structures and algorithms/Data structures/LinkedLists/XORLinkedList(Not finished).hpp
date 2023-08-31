#pragma once

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
	
	static Node* xorNext(Node* prev, Node* next) {
		return (XORLinkedList::Node*)((uintptr_t)prev ^ (uintptr_t)next);
	}


	Node* head = nullptr;
public:
	XORLinkedList() = default;
	XORLinkedList(const XORLinkedList&) = delete;
	XORLinkedList& operator=(const XORLinkedList&) = delete;
	~XORLinkedList();

	void push_back(const T& value);
	void print() const;
};
//
//template<typename T>
//XORLinkedList<T>::Node* XORLinkedList<T>::xorNext(Node* prev, Node* next) {
//	return (XORLinkedList::Node*)((uintptr_t)prev ^ (uintptr_t)next);
//}

template<typename T>
XORLinkedList<T>::~XORLinkedList() {}

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
	Node* prev = nullptr;
	Node* current = head;
	while (current) {
		std::cout << current->value << std::endl;
		current = xorNext(prev, current->xnode);
	}
}


//int main() {
//	XORLinkedList<int> xll;
//	xll.push_back(1);
//	xll.push_back(2);
//	xll.push_back(3);
//	xll.push_back(4);
//	xll.print();
//}
