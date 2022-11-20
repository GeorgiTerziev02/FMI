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

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<T>&);
	BinarySearchTree<T>& operator=(const BinarySearchTree<T>&);
	~BinarySearchTree();

	bool contains(const Node<T>*, const T&) const;
	void insert(const T&);

private:
	void copyFrom(const BinarySearchTree&);
	void free();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
	root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other) {
	copyFrom(other);
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}
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
bool BinarySearchTree<T>::contains(const Node<T>* root, const T& value) const {
	if (root == nullptr)
		return false;

	if (root->value == value)
		return true;

	return contains(root->value > value ? root->left : root->right, value);
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value) {
	if (root == nullptr) {
		root = new Node<T>(value);
		return;
	}


	// TODO:
}