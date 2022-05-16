#include <iostream>
#include "kPriorityQueue.hpp"

int main() {
	kPriorityQueue<char> q(4);

	q.enqueue('A', 0);
	q.enqueue('B', 3);
	q.enqueue('C', 2);
	q.enqueue('D', 2);
	q.enqueue('E', 1);

	std::cout << q.dequeue() << std::endl; // B
	std::cout << q.dequeue() << std::endl; // C
	std::cout << q.dequeue() << std::endl; // D
	std::cout << q.dequeue() << std::endl; // E
	std::cout << q.dequeue() << std::endl; // A
}