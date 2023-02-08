#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
    size_t elementsCount;
    std::cin >> elementsCount;
    std::vector<size_t> container(elementsCount);
    for(size_t i = 0; i < elementsCount; i++) {
        std::cin >> container[i];
    }
    
    size_t maxLength = 0, currentStartIndex = 0;
    // key - number, index - last seen at index
    std::unordered_map<size_t, size_t> lastSeen;
    
    for(size_t i = 0; i < elementsCount; i++) {
        if(lastSeen.find(container[i]) != lastSeen.end() 
           && currentStartIndex < lastSeen[container[i]] + 1 // prevent start index from moving backwards
        ) {
            currentStartIndex = lastSeen[container[i]] + 1;
        }
        
        lastSeen[container[i]] = i;
        
        if(i - currentStartIndex + 1 > maxLength) {
            maxLength = i - currentStartIndex + 1;
        }
    }
    
    std::cout << maxLength;
    
    return 0;
}