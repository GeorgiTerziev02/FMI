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
        
        // we found lower and upper bound
        if(firstLower != container.end() && firstUpper != container.end()) {
            // if they are the same => current is not in the array
            if(firstLower == firstUpper) {
                std::cout << firstUpper - container.begin();
            }
            else {
                // if we have the number in the container and we have a bigger number in the container
                std::cout << firstLower - container.begin() << " " << firstUpper - 1 - container.begin();
            }
        }
        // if we have lower but don't have upper => the number is the last number in the container
        else if(firstLower != container.end()) {
            std::cout << firstLower - container.begin() << " " << containerLength - 1;
        }
        // if we have upper but don't have lower => the number will be inserted at first index
        else if(firstUpper != container.end()) {
            std::cout << 0;
        }
        else {
            // all the numbers are lower than the search => last index
            std::cout << containerLength;
        }
        
        std::cout << '\n';
    }
    
    return 0;
}
