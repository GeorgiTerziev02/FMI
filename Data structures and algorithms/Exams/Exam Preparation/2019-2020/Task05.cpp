#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    size_t groupCount, interval, totalGroupsCount, queriesCount;
    std::cin >> groupCount >> interval >> totalGroupsCount >> queriesCount;
    
    std::priority_queue<size_t, std::vector<size_t>, std::greater<size_t>> toDoList;
    size_t doneGroups = 0;
    
    for(size_t i = 0; i < queriesCount; i++) {
        size_t current;
        std::cin >> current;
        toDoList.push(current);
        
        if((i + 1) % interval == 0) {
            for(size_t j = 0; j < groupCount && !toDoList.empty(); j++) {
                std::cout << toDoList.top() << " ";
                toDoList.pop();
            }
            
            if(++doneGroups == totalGroupsCount) {
                return 0;
            }
        }
    }
    
    while(doneGroups < totalGroupsCount && !toDoList.empty()) {
        for(size_t j = 0; j < groupCount && !toDoList.empty(); j++) {
            std::cout << toDoList.top() << " ";
            toDoList.pop();
        }
        doneGroups++;
    }

    return 0;
}