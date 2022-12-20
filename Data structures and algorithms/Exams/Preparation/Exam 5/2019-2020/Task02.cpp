#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

void bfs(std::vector<std::unordered_set<size_t>>& graph, std::vector<size_t>& result, size_t targetDistance) {
    std::unordered_set<size_t> visited;
    std::queue<size_t> container;
    container.push(graph.size() - 1);
    size_t currentDistance = 0;

    while (!container.empty()) {
        size_t length = container.size();

        while (length > 0) {
            size_t current = container.front();
            container.pop();

            if (!visited.count(current)) {
                visited.insert(current);
                if (currentDistance == targetDistance) {
                    result.push_back(current);
                }

                for (auto& val : graph[current]) {
                    container.push(val);
                }
            }

            length--;
        }

        currentDistance++;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t nodesCount, edgesCount, targetDistance;
    std::cin >> nodesCount >> edgesCount >> targetDistance;
    std::vector<std::unordered_set<size_t>> graph(nodesCount);

    for (size_t i = 0; i < edgesCount; i++) {
        size_t first, second;
        std::cin >> first >> second;

        graph[first - 1].insert(second - 1);
        graph[second - 1].insert(first - 1);
    }

    std::vector<size_t> result;

    bfs(graph, result, targetDistance);

    if (result.size() == 0) {
        std::cout << -1;
        return 0;
    }

    std::sort(result.begin(), result.end());

    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] + 1 << ' ';
    }

    return 0;
}
