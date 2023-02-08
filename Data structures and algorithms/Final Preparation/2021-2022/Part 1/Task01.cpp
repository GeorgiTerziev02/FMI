#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
    size_t rows, cols;
    std::cin >> rows >> cols;
    
    std::unordered_map<std::string, size_t> uniqueRows;
    for(size_t i = 0; i < rows; i++) {
        std::string currentRow(cols, '-');
        for(size_t j = 0; j < cols; j++) {
            std::cin >> currentRow[j];
        }
        
        uniqueRows[currentRow]++;
    }
    
    size_t result = 0;
    for(auto& kvp: uniqueRows) {
        if(kvp.second == 1) {
            result++;
        }
    }
    
    std::cout << result;
    
    return 0;
}