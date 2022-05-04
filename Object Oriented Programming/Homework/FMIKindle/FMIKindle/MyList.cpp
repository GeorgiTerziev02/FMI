#include "MyList.h"
#include "User.h"
#include "Book.h"

template<typename T>
MyList<T>::MyList() {
	data = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
MyList<T>::MyList(const MyList<T>& other) {
	copy(other);
}

template<typename T>
MyList<T>& MyList<T>::operator=(const MyList<T>& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

template<typename T>
MyList<T>& MyList<T>::operator=(MyList<T>&& other) {
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

template<typename T>
MyList<T>::~MyList() {
	free();
}

template<typename T>
T& MyList<T>::operator[](size_t index) {
	return data[index];
}

template<typename T>
T MyList<T>::operator[](size_t index) const {
	return data[index];
}

template<typename T>
T* MyList<T>::getData() const {
	return data;
}

template<typename T>
size_t MyList<T>::getSize() const {
	return size;
}

template<typename T>
size_t MyList<T>::getCapacity() const {
	return capacity;
}

template<typename T>
void MyList<T>::add(const T& newData) {
	// incrementing size directly because we are 
	// using the size property in the resize to know the old size
	// so that the resize method can be reused in case of addRange method
	if (size + 1 > capacity)
	{
		resize(size + 1);
	}

	data[size++] = newData;
}

template<typename T>
void MyList<T>::copy(const MyList<T>& other) {
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
void MyList<T>::free() {
	delete[] data;
}

template<typename T>
void MyList<T>::resize(const size_t expectedCapacityToFit) {
	capacity = calculateCapacity(expectedCapacityToFit);

	T* temp = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
}

template<typename T>
size_t MyList<T>::calculateCapacity(const size_t number) const {
	// initial size 4
	size_t num = 4;

	while (number > num) num *= 2;

	return num;
}

template class MyList<User>;
template class MyList<Book>;
template class MyList<Book*>;
template class MyList<char*>;
template class MyList<Page>;
template class MyList<Rating>;