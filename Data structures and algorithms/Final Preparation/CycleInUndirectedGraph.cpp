#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    size_t to, weight;  
};

bool hasCycle(std::vector<std::vector<Edge>>& graph, std::vector<bool>& visited, size_t current, long long prev) {
    visited[current] = true;
    
    for(auto& node: graph[current]) {
        if(node.to == prev) {
            continue;
        }
        
        if(visited[node.to]) {
            return true;
        }
        
        if(hasCycle(graph, visited, node.to, current)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    size_t q;
    std::cin >> q;
    for(size_t i = 0; i < q; i++) {

        size_t verticesCount, edgesCount;
        std::cin >> verticesCount >> edgesCount;

        std::vector<std::vector<Edge>> graph(verticesCount); 
        
        for(size_t j = 0; j < edgesCount; j++) {
            size_t from, to, weight;
            std::cin >> from >> to >> weight;
            graph[from - 1].push_back({ to - 1, weight});
            graph[to - 1].push_back({ from - 1, weight});
        }
        
        std::vector<bool> visited(verticesCount, false);
        
        bool flag = false;
        for(size_t j = 0; j < verticesCount; j ++) {
            if(!visited[j]) {
                if(hasCycle(graph, visited, j, -1)) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) {
            std::cout << "true ";
        } else {
            std::cout << "false ";
        }
    }
    return 0;
}
