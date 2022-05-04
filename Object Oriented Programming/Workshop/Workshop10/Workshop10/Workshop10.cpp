#include <iostream>
#include "Vector.hpp"

int main()
{
	Vector<int> test;
	for (size_t i = 0; i < 33; i++)
	{
		test.pushBack(i);
		std::cout << test[i] << " - capacity " << test.getCapacity() << std::endl;
	}
}