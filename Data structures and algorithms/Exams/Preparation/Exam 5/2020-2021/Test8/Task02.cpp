#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main()
{
    size_t n;
    std::cin >> n;

    std::unordered_map<size_t, size_t> container;
    for (size_t i = 0; i < n; i++) {
        size_t current;
        std::cin >> current;
        container[current]++;
        if (container[current] == 10) {
            container[current] -= 10;
        }
    }

    size_t count = 0, sum = 0;
    for (auto &current : container) {
        if (current.second > 0) {
            count++;
            sum += current.second;
        }
    }

    std::cout << count << " " << sum;

    return 0;
}