#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

struct Edge {
    int to, weight;
};

int searchedLength;
std::unordered_map<int, int> results;

void dfs(std::vector<std::vector<Edge>>& graph, std::vector<bool>& visited, int current, int depth, int currentSum) {
    if (searchedLength == depth) {
        results[currentSum]++;
        return;
    }

    visited[current] = true;

    for (auto& edge : graph[current]) {
        if (!visited[edge.to]) {
            dfs(graph, visited, edge.to, depth + 1, currentSum + edge.weight);
        }
    }

    visited[current] = false;
}

int main() {
    int verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;

    std::vector<std::vector<Edge>> graph(verticesCount);
    for (int i = 0; i < edgesCount; i++) {
        int from, to, weight;
        std::cin >> from >> to >> weight;
        graph[from - 1].push_back({ to - 1, weight });
    }

    std::cin >> searchedLength;

    for (int i = 0; i < verticesCount; i++) {
        std::vector<bool> visited(verticesCount, false);
        dfs(graph, visited, i, 0, 0);
    }

    int result = -1, max = 0;

    for (auto iter = results.begin(); iter != results.end(); ++iter) {
        if (iter->second > max) {
            max = iter->second;
            result = iter->first;
        }
        else if (iter->second == max && iter->first > result) {
            result = iter->first;
        }
    }

    std::cout << result;

    return 0;
}
