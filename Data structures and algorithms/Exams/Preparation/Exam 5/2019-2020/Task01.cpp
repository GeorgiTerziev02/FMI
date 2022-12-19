#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, size_t> container;
    
    size_t townsCount, pathLengthCount;
    std::cin >> townsCount >> pathLengthCount;
    for(size_t i = 0; i < townsCount; i++){
        std::string townName;
        size_t tax;
        std::cin >> townName >> tax;
        container[townName] = tax;
    }
    
    size_t sum = 0;
    
    for(size_t i = 0; i < pathLengthCount; i++){
        std::string townName;
        std::cin >> townName;
        
        sum+= container[townName];
    }
    
    std::cout << sum;
    
    return 0;
}
