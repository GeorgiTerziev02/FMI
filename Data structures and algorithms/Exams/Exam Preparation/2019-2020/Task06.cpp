#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Edge{
    size_t from, to, weight;
    
    bool operator<(const Edge& rhs) const {
        return this->weight > rhs.weight;
    }
};

class UnionFind{
private:
    std::vector<size_t> parentsContainer;
    
    size_t getParent(size_t vertex) {
        if(parentsContainer[vertex] == vertex) {
            return vertex;
        }
        
        return parentsContainer[vertex] = getParent(parentsContainer[vertex]);
    }
public:
    UnionFind(size_t verticesCount): parentsContainer(verticesCount) {
        for(size_t i = 0; i < verticesCount; i++) {
            parentsContainer[i] = i;
        }
    }
    
    bool areInOneSet(size_t first, size_t second) {
        return getParent(first) == getParent(second);
    }
    
    void unionVertices(size_t first, size_t second) {
        size_t parentOfFirst = getParent(first);
        size_t parentOfSecond = getParent(second);
        
        parentsContainer[parentOfFirst] = parentOfSecond;
    }
};

size_t sum(const std::vector<Edge>& edgesContainer) {
    size_t result = 0;
    for(size_t i = 0; i < edgesContainer.size(); i++) {
        result += edgesContainer[i].weight;
    }
    
    return result;
}

int main() {
    size_t verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;
    
    std::vector<Edge> edgesContainer(edgesCount);
    
    for(size_t i = 0; i < edgesCount; i++) {
        std::cin >> edgesContainer[i].from >> edgesContainer[i].to >> edgesContainer[i].weight;
    }
    
    std::sort(edgesContainer.begin(), edgesContainer.end());
    
    size_t totalSum = sum(edgesContainer);
    size_t usedSum = 0;
    
    UnionFind graph(verticesCount);
    
    for(auto& edge: edgesContainer) {
        if(graph.areInOneSet(edge.from, edge.to)) {
            continue;
        }
        
        usedSum += edge.weight;
        graph.unionVertices(edge.from, edge.to);
    }
    
    std::cout << totalSum - usedSum;
    
    return 0;
}