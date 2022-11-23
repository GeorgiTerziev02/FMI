template <typename T>
struct Node {
	T value;
	Node* left;
	Node* right;

	Node(const T& value, Node* left = nullptr, Node* right = nullptr) {
		this->value = value;
		this->left = left;
		this->right = right;
	}

	~Node() {
		delete left;
		delete right;
	}
};

template <typename T>
class BinarySearchTree {
private:
	Node<T>* root;

	Node<T>* _insert(Node<T>* current, const T& value);
	bool _contains(Node<T>* current, const T& value) const;
	Node<T>* _remove(Node<T>* current, const T& value);

public:
	BinarySearchTree();
	//BinarySearchTree(const BinarySearchTree<T>&);
	//BinarySearchTree<T>& operator=(const BinarySearchTree<T>&);
	~BinarySearchTree();

	bool contains(const T& value) const;
	void insert(const T& value);
	void remove(const T& value);

private:
	//void copyFrom(const BinarySearchTree&);
	void free();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
	root = nullptr;
}

//template <typename T>
//BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other) {
//	copyFrom(other);
//}
//
//template <typename T>
//BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& other) {
//	if (this != &other) {
//		free();
//		copyFrom(other);
//	}
//
//	return *this;
//}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	free();
}

//template <typename T>
//void BinarySearchTree<T>::copyFrom(const BinarySearchTree<T>& other) {
//	// TODO: 
//}
//

template <typename T>
void BinarySearchTree<T>::free() {
	delete root;
}

template <typename T>
Node<T>* BinarySearchTree<T>::_insert(Node<T>* current, const T& value) {
	if (!current) {
		return new Node<T>(value);
	}

	if (current->value < value) {
		current->right = _insert(current->right, value);
	}
	else if (value < current->value) {
		current->left = _insert(current->left, value);
	}

	return current;
}

template <typename T>
bool BinarySearchTree<T>::_contains(Node<T>* current, const T& value) const {
	if (!current) {
		return false;
	}

	if (current->value == value) {
		return true;
	}

	return current->value > value ? contains(current->left, value) : contains(current->right, value);
}	

template <typename T>
Node<T>* BinarySearchTree<T>::_remove(Node<T>* current, const T& value) {
	if (!current) {
		return nullptr;
	}

	if (value < current->value) {
		current->left = _remove(current->left, value);
	}
	else if (current->value < value) {
		current->right = _remove(current->right, value);
	}
	else {
		if (!current->left && !current->right) {
			return nullptr;
		}
		else if (!current->left) {
			return current->right;
		}
		else if (!current->right) {
			return current->left;
		}
		else {
			Node<T>* iter = current->right;

			while (iter->left) {
				iter = iter->left;
			}

			current->value = iter->value;
			current->right = _remove(current->right, current->value);
		}
	}

	return current;
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& value) const {
	return _contains(root, value);
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value) {
	root = _insert(root, value);
}

template <typename T>
void BinarySearchTree<T>::remove(const T& value) {
	root = _remove(root, value);
}
