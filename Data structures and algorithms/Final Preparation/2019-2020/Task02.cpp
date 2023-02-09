#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    size_t containerLength;
    std::cin >> containerLength;
    std::vector<long> container(containerLength);
    for(size_t i = 0; i < containerLength; i++) {
        std::cin >> container[i];
    }
    
    size_t queriesCount;
    std::cin >> queriesCount;
    for(size_t i = 0; i < queriesCount; i++) {
        long current;
        std::cin >> current;
        
        auto firstLower = lower_bound(container.begin(), container.end(), current);
        auto firstUpper = upper_bound(container.begin(), container.end(), current);
        
        if(firstLower == firstUpper) {
            std::cout << firstUpper - container.begin();
        }
        else {
            // if we have the number in the container and we have a bigger number in the container
            std::cout << firstLower - container.begin() << " " << firstUpper - 1 - container.begin();
        }
        
        std::cout << '\n';
    }
    
    return 0;
}
