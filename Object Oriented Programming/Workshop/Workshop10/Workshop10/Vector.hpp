#pragma once

const size_t DEFAULT_CAPACITY = 4;

template <typename T>
class Vector {
private:
	T* data;
	size_t size;
	size_t capacity;

public:
	Vector();
	Vector(const Vector<T>&);
	Vector(Vector<T>&&);
	Vector<T>& operator=(const Vector<T>&);
	Vector<T>& operator=(Vector<T>&&);
	~Vector();

	size_t getSize() const;
	size_t getCapacity() const;

	void pushBack(const T& n);
	void pushBack(T&& n);
	void pushAt(const T& n, const size_t index);
	void pushAt(T&& n, const size_t index);
	T& popBack();
	T& popAt(const size_t index);
	T& operator[](const size_t index);
	const T& operator[](const size_t index) const;
	bool empty() const;
	void clear(); 
	void swap(const Vector<T>& other);
private:
	void copy(const Vector&);
	void free();

	size_t calculateCapacity(const size_t number) const;
	void resize(const size_t expectedCapacityToFit);
};

template <typename T>
Vector<T>::Vector() {
	data = nullptr;
	size = 0;
	capacity = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
	copy(other);
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other) {
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) {
	if (this != &other)
	{
		free();
		data = other.data;
		size = other.size;
		capacity = other.capacity;

		other.data = nullptr;
	}

	return *this;
}

template <typename T>
Vector<T>::~Vector() {
	free();
}

template <typename T>
size_t Vector<T>::getSize() const {
	return size;
}

template <typename T>
size_t Vector<T>::getCapacity() const {
	return capacity;
}

template <typename T>
void Vector<T>::pushBack(const T& n) {
	if (size + 1 > capacity) resize(size + 1);

	data[size++] = n;
}


template <typename T>
void Vector<T>::pushBack(T&& n) {
	if (size + 1 > capacity) resize(size + 1);

	data[size++] = n;
}

template <typename T>
void Vector<T>::pushAt(const T& n, const size_t index) {
	if (size + 1 > capacity) resize(size + 1);

	for (size_t i = size; i > index; i--)
		data[i] = data[i - 1];

	data[index] = n;
	size++;
}

template <typename T>
void Vector<T>::pushAt(T&& n, const size_t index) {
	if (size + 1 > capacity) resize(size + 1);

	for (size_t i = size; i > index; i--)
		data[i] = data[i - 1];

	data[index] = n;
	size++;
}

template <typename T>
T& Vector<T>::popBack() {
	if (empty())
		throw "Vector is empty";

	return data[--size];
}

template <typename T>
T& Vector<T>::popAt(size_t index) {
	if (index < 0 || index >= size)
		throw "Invalid index";

	T temp = data[index];
	for (size_t i = index; i < size - 1; i++)
		data[i] = data[i + 1];

	return temp;
}

template <typename T>
T& Vector<T>::operator[](const size_t index) {
	if (index < 0 || index >= size)
		throw "Invalid index";

	return data[index];
}

template <typename T>
const T& Vector<T>::operator[](const size_t index) const {
	if (index < 0 || index >= size)
		throw "Invalid index";

	return data[index];
}

template <typename T>
bool Vector<T>::empty() const {
	return size == 0;
}

template <typename T>
void Vector<T>::clear() {
	delete[] data;
	capacity = DEFAULT_CAPACITY;
	data = new T[capacity];
	size = 0;
}

template <typename T>
void Vector<T>::swap(const Vector<T>& other) {
	T* tempData = this->data;
	size_t tempSize = this->size;
	size_t tempCapacity = this->capacity;

	this->data = other.data;
	this->size = other.size;
	this->capacity = other.capacity;

	other.data = tempData;
	other.size = tempSize;
	other.capacity = tempCapacity;
}

template <typename T>
void Vector<T>::copy(const Vector<T>& other) {
	size = other.size;
	capacity = other.capacity;
	data = new T[size];

	for (size_t i = 0; i < size; i++)
		data[i] = other[i];
}

template <typename T>
void Vector<T>::free() {
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

template <typename T>
size_t Vector<T>::calculateCapacity(const size_t number) const {
	size_t result = DEFAULT_CAPACITY;
	while (number > result) 
		result *= 2;

	return result;
}

template <typename T>
void Vector<T>::resize(const size_t expectedCapacityToFit) {
	capacity = calculateCapacity(expectedCapacityToFit);
	T* temp = new T[capacity];

	for (size_t i = 0; i < size; i++) 
		temp[i] = data[i];

	delete[] data;
	data = temp;
}