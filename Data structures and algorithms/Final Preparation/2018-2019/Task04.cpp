#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

bool hasCycle(std::vector<std::vector<size_t>>& graph, std::vector<bool>& visited, size_t start) {
    visited[start] = true;

    for(auto& neighbour: graph[start]) {
        if(visited[neighbour]) {
            return true;
        }
        
        if(hasCycle(graph, visited, neighbour)) {
            return true;
        }
    }

    visited[start] = false;

    return false;
}

int main() {
    size_t queriesCount;
    std::cin >> queriesCount;
    
    for(size_t i = 0; i < queriesCount; i++) {
        size_t verticesCount, edgesCount;
        std::cin >> verticesCount >> edgesCount;
        
        std::vector<std::vector<size_t>> graph(verticesCount);
        for(size_t j = 0; j < edgesCount; j++) {
            size_t from, to, weight;
            std::cin >> from >> to >> weight;
            graph[from - 1].push_back(to - 1);
        }
        
        std::vector<bool> visited(verticesCount, false);
        bool foundCycle = false;
        for(size_t i = 0; i < verticesCount; i++) {
            if(visited[i]) {
                continue;
            }
            
            foundCycle = hasCycle(graph, visited, i);
                
            if(foundCycle) {
                break;
            }
        }
        
        std::cout << std::boolalpha << foundCycle << " ";
    }
    
    return 0;
}
