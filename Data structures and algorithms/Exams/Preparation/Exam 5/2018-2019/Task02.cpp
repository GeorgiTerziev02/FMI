#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

size_t shortestPathsSum(std::vector<std::unordered_set<size_t>>& graph) { 
    std::vector<long long> visitedAt(graph.size(), -1);
    std::queue<size_t> container;
    container.push(0);
    
    size_t currentLength = 0;
    while(!container.empty()) {
        size_t nodesLength = container.size();
        
        while(nodesLength > 0) {
            size_t currentNode = container.front();
            container.pop();
            
            if(visitedAt[currentNode] == -1) {
                visitedAt[currentNode] = currentLength;
                for(auto& value: graph[currentNode]) {
                    container.push(value);
                }
            }        
            
            nodesLength--;   
        }
        
        currentLength++;
    }
    
    size_t sum = 0;
    for(size_t i = 0; i < visitedAt.size(); i++) {
        if(visitedAt[i] != -1) {
            sum += visitedAt[i];
        }
    }
    
    return sum;
}

int main() {
    size_t edgesCount;
    std::cin >> edgesCount;
    
    std::vector<std::unordered_set<size_t>> graph(edgesCount + 1);
    
    for(size_t i = 0; i < edgesCount; i++) {
        size_t first, second;
        std::cin >> first >> second;
        
        graph[first].insert(second);
        graph[second].insert(first);
    }
    
    std::cout << shortestPathsSum(graph);
    
    return 0;
}