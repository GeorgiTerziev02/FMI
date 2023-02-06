#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::string input;
    std::cin >> input;
    
    int counter[256] = { 0 };
    for(size_t i = 0; i < input.size(); i++){
        counter[input[i]]++;    
    }
    
    for(size_t i = 0; i < input.size(); i++){
        if(counter[input[i]] == 1)
            std::cout << i << " ";
    }
    
    return 0;
}