#pragma once

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
	T operator[](size_t) const;

	T* getData() const;
	size_t getSize() const;
	size_t getCapacity() const;

	void add(const T&);
private:
	void copy(const MyList<T>&);
	void free();

	void resize(const size_t expectedCapacityToFit);

	size_t calculateCapacity(const size_t number) const;
};

