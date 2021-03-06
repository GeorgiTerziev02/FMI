#pragma once

const size_t DEFAULT_CAPACITY = 4;

template<typename T>
class MyList
{
private:
	T* data;
	size_t size;
	size_t capacity;
public:
	MyList();
	MyList(const MyList<T>&);
	MyList<T>& operator=(const MyList<T>&);
	MyList<T>& operator=(MyList<T>&&);
	~MyList();

	T& operator[](size_t);
	const T& operator[](size_t) const;

	T* getData() const;
	size_t getSize() const;
	size_t getCapacity() const;
	void clear();

	void add(const T&);
private:
	void copy(const MyList<T>&);
	void free();

	void resize(const size_t expectedCapacityToFit);

	size_t calculateCapacity(const size_t number) const;
};

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
		other.size = 0;
		other.capacity = 0;
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
const T& MyList<T>::operator[](size_t index) const {
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
		resize(size + 1);

	data[size++] = newData;
}

template<typename T>
void MyList<T>::copy(const MyList<T>& other) {
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];

	for (size_t i = 0; i < size; i++)
		data[i] = other.data[i];
}

template<typename T>
void MyList<T>::free() {
	delete[] data;
}

template <typename T>
void MyList<T>::clear() {
	delete[] data;
	capacity = DEFAULT_CAPACITY;
	data = new T[capacity];
	size = 0;
}

template<typename T>
void MyList<T>::resize(const size_t expectedCapacityToFit) {
	capacity = calculateCapacity(expectedCapacityToFit);

	T* temp = new T[capacity];
	for (size_t i = 0; i < size; i++)
		temp[i] = data[i];

	delete[] data;
	data = temp;
}

template<typename T>
size_t MyList<T>::calculateCapacity(const size_t number) const {
	size_t num = DEFAULT_CAPACITY;

	while (number > num) num *= 2;

	return num;
}