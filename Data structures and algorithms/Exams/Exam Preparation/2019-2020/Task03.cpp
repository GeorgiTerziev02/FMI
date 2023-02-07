#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void dfs(const std::vector<std::vector<size_t>>& graph, std::vector<bool>& visited, size_t current) {
    visited[current] = true;
    
    for(auto& neighbour: graph[current]) {
        if(visited[neighbour]) {
            continue;
        }
        
        dfs(graph, visited, neighbour);
    }
}

int main() {
    size_t queriesCount;
    std::cin >> queriesCount;
    
    for(size_t i = 0; i < queriesCount; i++) {
        size_t verticesCount, edgesCount;
        std::cin >> verticesCount >> edgesCount;
        
        std::vector<std::vector<size_t>> graph(verticesCount);
        for(size_t j = 0; j < edgesCount; j++) {
            size_t from, to;
            std::cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        
        std::vector<bool> visited(verticesCount);
        size_t componentsCount = 0;
        for(size_t j = 0; j < verticesCount; j++) {
            if(visited[j]) {
                continue;
            }
            
            dfs(graph, visited, j);
            componentsCount++;
        }
        
        std::cout << componentsCount << " ";
    }
    
    return 0;
}
