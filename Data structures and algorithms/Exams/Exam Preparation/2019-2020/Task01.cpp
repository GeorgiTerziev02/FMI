#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

bool adjacencyMatrix[1001][1001] = {};
// second matrix saves us if we have a weight that is equal to 0
long weightMatrix[1001][1001] = {};

int main() {
    size_t verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;
    
    for(size_t i = 0; i < edgesCount; i++) {
        size_t from, to, weight;
        std::cin >> from >> to >> weight;
        adjacencyMatrix[from][to] = true;
        adjacencyMatrix[to][from] = true;
        weightMatrix[from][to] = weight;
        weightMatrix[to][from] = weight;
    }
    
    size_t pathLength;
    std::cin >> pathLength;
    std::vector<size_t> path(pathLength);
    
    for(size_t i = 0; i < pathLength; i++) {
        std::cin >> path[i];
    }
    
    size_t result = 0;
    bool pathExists = true;
    for(size_t i = 1; i < pathLength; i++) {
        if(!adjacencyMatrix[path[i]][path[i - 1]]) {
            pathExists = false;
            break;
        }
        
        result += weightMatrix[path[i]][path[i - 1]];
    }
    
    if(pathExists) {
        std::cout << result;
    }
    else {
        std::cout << -1;
    }
    
    return 0;
}
