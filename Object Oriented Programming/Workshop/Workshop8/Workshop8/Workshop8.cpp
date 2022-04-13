#include <iostream>
#include "Nvector.h"
#include "DecartCoordinateSystem.h"

int main()
{
	//Nvector v(4);
	//std::cin >> v;

	//Nvector v2(4);
	//std::cin >> v2;

	//Nvector result = v + v2;
	//std::cout << result << std::endl;


	Nvector v1(2);
	v1[0] = 2;
	v1[1] = 1;

	Nvector v2(2);
	v2[0] = 3;
	v2[1] = 1;

	DecartCoordinateSystem s(v1, v2);

	std::cout << s.getVectorByCoordinates(7, 4); // [26, 11]
	std::cout << std::endl;
	std::cout << s.getCoordinatesByVector(7, 4); // [5, -1]
}