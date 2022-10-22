#include <iostream>

void task3()
{
	int counter[257] = { 0 };
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	for (size_t i = 0; i < n; i++)
		counter[int(s[i])]++;


	for (size_t i = 48; i <= 57; i++)
		if (counter[i] > 0)
			for (size_t j = 0; j < counter[i]; j++)
				std::cout << char(i);
	for (size_t i = 97; i <= 122; i++)
		for (size_t j = 0; j < counter[i]; j++)
			std::cout << char(i);
	for (size_t i = 65; i <= 90; i++)
		for (size_t j = 0; j < counter[i]; j++)
			std::cout << char(i);
}