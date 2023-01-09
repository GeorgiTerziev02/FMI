#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

bool hasCycle(
    std::vector<std::vector<long long>>& graph, 
    std::unordered_set<long long>& visited, 
    long long current
) {
    visited.insert(current);

    for (size_t i = 0; i < graph[current].size(); i++) {
        long long node = graph[current][i];
        if(visited.count(node)) {
            return true;
        }
            
        if (hasCycle(graph, visited, node)) {
            return true;
        }
    }
    
    visited.erase(current);

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    long long requests;
    
    std::cin >> requests;
    std::string result = "";
    for(long long j = 0; j < requests; j++) {
        long long nodesCount, edgesCount;
        std::cin >> nodesCount >> edgesCount;
        std::vector<std::vector<long long>> graph(nodesCount + 1);

        for (long long i = 0; i < edgesCount; i++) {
            long long first, second, weight;
            std::cin >> first >> second >> weight;

            graph[first].push_back(second);
        }

        std::unordered_set<long long> visited;
        
        bool flag = false;
        for(size_t i = 0; i < graph.size(); i++) {
            if(visited.count(i) == 0) {
                if(hasCycle(graph, visited, i)) {
                      flag = true;
                      break;
                }
            }
        }
        
        result += (flag ? '1' : '0');
    }
    
    std::cout << result;
    return 0;
}