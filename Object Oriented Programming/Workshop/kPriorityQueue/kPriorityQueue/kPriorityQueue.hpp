#pragma once
#include "Queue.hpp"

template<typename T>
class kPriorityQueue {
	Queue<T>* queues;
	size_t maxPriority;
public:
	kPriorityQueue();
	kPriorityQueue(const size_t);
	kPriorityQueue(const kPriorityQueue<T>&);
	kPriorityQueue<T>& operator=(const kPriorityQueue<T>&);
	~kPriorityQueue();

	void enqueue(const T&, const size_t);
	T dequeue();
	T& peek() const;

private:
	void copyFrom(const kPriorityQueue<T>&);
	void free();
};

template<typename T>
kPriorityQueue<T>::kPriorityQueue() {
	queues = nullptr;
	maxPriority = 0;
}

template<typename T>
kPriorityQueue<T>::kPriorityQueue(const size_t maxPriority) {
	this->maxPriority = maxPriority;
	this->queues = new Queue<T>[maxPriority];
}

template<typename T>
kPriorityQueue<T>::kPriorityQueue(const kPriorityQueue<T>& other) {
	copyFrom(other);
}

template<typename T>
kPriorityQueue<T>& kPriorityQueue<T>::operator=(const kPriorityQueue<T>& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
kPriorityQueue<T>::~kPriorityQueue() {
	free();
}

template<typename T>
void kPriorityQueue<T>::copyFrom(const kPriorityQueue<T>& other) {
	this->maxPriority = other.maxPriority;
	queues = new Queue<T>[maxPriority];

	for (size_t i = 0; i < maxPriority; i++)
		queues[i] = other.queues[i];
}

template<typename T>
void kPriorityQueue<T>::free() {
	delete[] queues;
	maxPriority = 0;
}

template<typename T>
void kPriorityQueue<T>::enqueue(const T& element, const size_t priority) {
	if (priority < 0 || priority >= maxPriority)
		throw "Invalid priority!";

	queues[priority].enqueue(element);
}

template<typename T>
T kPriorityQueue<T>::dequeue() {
	for (int i = maxPriority - 1; i >= 0; i--)
		if (!queues[i].isEmpty())
			return queues[i].dequeue();
}

template<typename T>
T& kPriorityQueue<T>::peek() const {
	for (int i = maxPriority - 1; i >= 0; i--)
		if (!queues[i]->isEmpty())
			queues[i].peek();
}
