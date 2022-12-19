#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

int main()
{
    std::unordered_set<size_t> container;
    std::vector<size_t> numbers;

    size_t n;
    std::cin >> n;

    for (size_t i = 0; i < n; i++) {
        size_t current;
        std::cin >> current;
        container.insert(current);
        numbers.push_back(current);
    }

    for (size_t i = 0; i < numbers.size() - 1; i++) {
        for (size_t j = i + 1; j < numbers.size(); j++) {
            if (container.count(numbers[i] + numbers[j])) {
                std::cout << "true";
                return 0;
            }
        }
    }

    std::cout << "false";
    return 0;
}