#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

struct Node {
    std::unordered_set<size_t> nodes;
};

void dfs(std::vector<Node>& graph, std::unordered_set<size_t>& visited, size_t current) {
    visited.insert(current);

    for (auto& iter : graph[current].nodes) {
        if (!visited.count(iter))
            dfs(graph, visited, iter);
    }
}

size_t createComponents(std::vector<Node>& graph) {
    size_t componentIndex = 0;
    std::unordered_set<size_t> visited;

    for (size_t i = 0; i < graph.size(); i++) {
        if (!visited.count(i)) {
            dfs(graph, visited, i);
            componentIndex++;
        }
    }

    return componentIndex;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    size_t queriesCount;
    std::cin >> queriesCount;

    for (size_t i = 0; i < queriesCount; i++) {
        size_t nodesCount, edgesCount;
        std::cin >> nodesCount >> edgesCount;

        std::vector<Node> graph(nodesCount);

        for (size_t j = 0; j < edgesCount; j++) {
            size_t first, second;
            std::cin >> first >> second;
            graph[first].nodes.insert(second);
            graph[second].nodes.insert(first);
        }

        std::cout << createComponents(graph) << ' ';
    }

    return 0;
}