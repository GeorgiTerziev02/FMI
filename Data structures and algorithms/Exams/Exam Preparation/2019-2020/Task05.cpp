#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

long shortestPath(std::vector<std::vector<size_t>>& graph, size_t from, size_t to, std::unordered_set<size_t>& notToVisit) {
    std::queue<size_t> toProcess;
    toProcess.push(from);
    
    long resultPathLength = -1;
    long currentLevel = 0;
    while(!toProcess.empty()) {
        size_t levelLength = toProcess.size();
        
        while(levelLength > 0) {
            size_t current = toProcess.front();
            toProcess.pop();
            
            if(current == to) {
                resultPathLength = currentLevel;
                break;
            }
        
            for(auto& adj: graph[current]) {
                if(notToVisit.count(adj) == 0) {
                    toProcess.push(adj);
                }
            }
            
            levelLength--;
        }
        
        if(resultPathLength != - 1) {
            break;
        }
        
        currentLevel++;
    }
    
    return resultPathLength;
}

int main() {
    size_t verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;
    std::vector<std::vector<size_t>> graph(verticesCount);
    
    for(size_t i = 0; i < edgesCount; i++) {
        size_t from, to;
        std::cin >> from >> to;
        graph[from].push_back(to);
    }
    
    size_t attractionsCount;
    std::cin >> attractionsCount;
    std::vector<size_t> attractions(attractionsCount);
    std::unordered_set<size_t> notToVisit;
    for(size_t i = 0; i < attractionsCount; i++) {
        std::cin >> attractions[i];
        notToVisit.insert(attractions[i]);
    }
    
    notToVisit.erase(attractions[0]);
    long totalPath = 0;
    for(size_t i = 1; i < attractionsCount; i++) {
        notToVisit.erase(attractions[i]);
        long pathLength = shortestPath(graph, attractions[i - 1], attractions[i], notToVisit);
        if(pathLength == -1) {
            totalPath = -1;
            break;
        }
        
        totalPath += pathLength;
    }
    
    std::cout << totalPath;
    
    return 0;
}