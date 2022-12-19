#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

bool graph[1000][1000];

bool hasPath(std::vector<size_t> &towns) {
    for (size_t j = 0; j < towns.size() - 1; j++) {
        if (!graph[towns[j]][towns[j + 1]]) {
            return false;
        }
    }

    return true;
}

int main()
{
    size_t nodesCount;
    std::cin >> nodesCount;

    for (size_t i = 0; i < nodesCount; i++) {
        size_t count;
        std::cin >> count;

        for (size_t j = 0; j < count; j++) {
            size_t current;
            std::cin >> current;

            graph[i][current] = 1;
            graph[current][i] = 1;
        }
    }

    size_t pathsCount;
    std::cin >> pathsCount;

    for (size_t i = 0; i < pathsCount; i++) {
        size_t pathLength;
        std::cin >> pathLength;
        std::vector<size_t> pathTowns(pathLength);
        for (size_t j = 0; j < pathLength; j++) {
            std::cin >> pathTowns[j];
        }

        std::cout << hasPath(pathTowns) << ' ';
    }

    return 0;
}
