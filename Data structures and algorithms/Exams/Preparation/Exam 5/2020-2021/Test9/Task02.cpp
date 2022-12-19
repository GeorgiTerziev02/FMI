#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

void dfs(std::vector<std::unordered_set<size_t>>& graph, std::vector<bool>& visited, size_t current) {
    visited[current] = true;

    for (auto& iter : graph[current]) {
        if (!visited[iter])
            dfs(graph, visited, iter);
    }
}

size_t createComponets(std::vector<std::unordered_set<size_t>>& graph) {
    size_t componentIndex = 0;
    std::vector<bool> visited(graph.size(), false);

    for (size_t i = 0; i < graph.size(); i++) {
        if (!visited[i] && graph[i].size() > 0) {
            dfs(graph, visited, i);
            componentIndex++;
        }
    }


    return componentIndex;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    size_t nodesCount, edgesCount;
    std::cin >> nodesCount >> edgesCount;
    std::vector<std::unordered_set<size_t>> graph(nodesCount);

    for (size_t i = 0; i < edgesCount; i++) {
        size_t first, second;
        std::cin >> first >> second;
        graph[first].insert(second);
        graph[second].insert(first);
    }

    std::cout << createComponets(graph);

    return 0;
}
