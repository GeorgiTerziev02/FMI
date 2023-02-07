#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Vertice {
    size_t componentIndex = 0;
    std::vector<size_t> adjacencyLists;
};

void createComponent(std::vector<Vertice>& graph, std::vector<bool>& visited, size_t current, const size_t& componentIndex) {
    visited[current] = true;
    graph[current].componentIndex = componentIndex;
    
    for(auto& adj: graph[current].adjacencyLists) {
        if(!visited[adj]) {
            createComponent(graph, visited, adj, componentIndex);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    size_t verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;
    std::vector<Vertice> graph(verticesCount);
    
    for(size_t i = 0; i < edgesCount; i++) {
        size_t from, to;
        std::cin >> from >> to;
        graph[from - 1].adjacencyLists.push_back(to - 1);
        graph[to - 1].adjacencyLists.push_back(from - 1);
    }
    
    std::vector<bool> visitedVertices(verticesCount, false);
    size_t componentIndex = 0;
    for(size_t i = 0; i < verticesCount; i++) {
        if(!visitedVertices[i]) {
            createComponent(graph, visitedVertices, i, componentIndex);
            componentIndex++;
        }
    }
    
    size_t queriesCount;
    std::cin >> queriesCount;
    
    for(size_t i = 0; i < queriesCount; i++) {
        size_t from, to;
        std::cin >> from >> to;
        std::cout << (graph[from - 1].componentIndex == graph[to - 1].componentIndex) << " ";
    }
    
    return 0;
}