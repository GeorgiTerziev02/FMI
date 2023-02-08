#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>

struct Vertice {
    size_t index; // equalToWeight;
    size_t childrenSum = 0;
    std::vector<size_t> children;
};

// returns sum of childs
size_t dfs(std::unordered_map<size_t, Vertice>& graph, std::unordered_set<size_t>& visited, size_t current) {
    visited.insert(current);
    size_t childrenSum = 0;
    for (auto& child : graph[current].children) {
        if (visited.count(child) > 0) {
            childrenSum += graph[child].childrenSum + child;
        }
        else {
            childrenSum += dfs(graph, visited, child);
        }
    }

    graph[current].childrenSum = childrenSum;
    return childrenSum + current;
}

int main() {
    size_t edgesCount, queriesCount;
    std::cin >> edgesCount >> queriesCount;

    std::unordered_map<size_t, Vertice> graph;

    for (size_t i = 0; i < edgesCount; i++) {
        size_t from, to;
        std::cin >> from >> to;
        graph[from].children.push_back(to);
        graph[to];
    }

    std::unordered_set<size_t> visited;
    for (auto& kvp : graph) {
        if (visited.count(kvp.first) == 0) {
            dfs(graph, visited, kvp.first);
        }
    }

    for (size_t i = 0; i < queriesCount; i++) {
        size_t vertice;
        std::cin >> vertice;
        std::cout << graph[vertice].childrenSum << '\n';
    }

    return 0;
}
