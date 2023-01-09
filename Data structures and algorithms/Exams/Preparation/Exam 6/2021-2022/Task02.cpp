#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct Edge {
    size_t to, weight;
};

bool hasPath(std::unordered_set<size_t>& magicNumbers, std::vector<std::vector<Edge>>& graph, size_t from, size_t to) {
    bool result = false;

    for (size_t i = 0; i < graph[from].size(); i++) {
        if (graph[from][i].to == to && magicNumbers.count(graph[from][i].weight) == 0) {
            result = true;
            break;
        }
    }

    return result;
}

int main() {
    size_t verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;

    std::vector<std::vector<Edge>> graph(verticesCount);
    for (size_t i = 0; i < edgesCount; i++) {
        size_t from, to, weight;
        std::cin >> from >> to >> weight;
        graph[from].push_back({ to, weight });
    }

    size_t magicNumbersCount;
    std::cin >> magicNumbersCount;
    std::unordered_set<size_t> magicNumbers;

    for (size_t i = 0; i < magicNumbersCount; i++) {
        size_t current;
        std::cin >> current;
        magicNumbers.insert(current);
    }

    size_t queriesCount;
    std::cin >> queriesCount;

    string result = "";
    for (size_t i = 0; i < queriesCount; i++) {
        size_t pathLength;
        std::cin >> pathLength;
        std::vector<size_t> path(pathLength);

        for (size_t j = 0; j < pathLength; j++) {
            size_t current;
            std::cin >> current;
            path[j] = current;
        }

        bool flag = true;
        for (size_t j = 0; j < path.size() - 1; j++) {
            if (!hasPath(magicNumbers, graph, path[j], path[j + 1])) {
                flag = false;
                break;
            }
        }

        result += (flag ? '1' : '0');
    }

    std::cout << result;

    return 0;
}