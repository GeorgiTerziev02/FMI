#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
    size_t size;
    std::cin >> size;
    // key - element value, value - position in the array
    std::unordered_map<size_t, size_t> numbersCounter;
    std::vector<size_t> inputNumbers(size);

    for (size_t i = 0; i < size; i++) {
        std::cin >> inputNumbers[i];
        numbersCounter[inputNumbers[i]]++;
    }
    
    std::vector<size_t> duplicates;
    for(size_t i = 0; i < size; i++) {
        if(numbersCounter.find(inputNumbers[i]) != numbersCounter.end()) {
            if(numbersCounter[inputNumbers[i]] == 1) {
                std::cout << inputNumbers[i] << " ";
            }
            else {
                duplicates.push_back(inputNumbers[i]);
                numbersCounter.erase(inputNumbers[i]);
            }
        }
    }
    
    for(size_t i = 0; i < duplicates.size(); i++) {
        std::cout << duplicates[i] << " ";
    }
     
    return 0;
}
