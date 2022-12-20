#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

bool hasCycle(
    std::vector<std::unordered_set<size_t>>& graph, 
    std::unordered_set<size_t>& visited, 
    size_t prev,
    size_t current
) {
    visited.insert(current);

    for (auto& node : graph[current]) {
        if (visited.count(node) && prev != node) {
            return true;
        }

        if (!visited.count(node)) {
            if (hasCycle(graph, visited, current, node)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t nodesCount, edgesCount;
    std::cin >> nodesCount >> edgesCount;
    std::vector<std::unordered_set<size_t>> graph(nodesCount + 1);

    for (size_t i = 0; i < edgesCount; i++) {
        size_t first, second;
        std::cin >> first >> second;

        graph[first].insert(second);
        graph[second].insert(first);
    }

    std::unordered_set<size_t> visited;
    
    std::cout << hasCycle(graph, visited, 0, 1);

    return 0;
}
