#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

// returns the maximum cooked pancakes for a given time
size_t possibleCookedForTime(std::vector<size_t>& cookerTimes, size_t time) {
    size_t result = 0;
    
    for(size_t i = 0; i < cookerTimes.size(); i++) {
        result += (time / cookerTimes[i]);
    }
    
    return result;
}

int main() {
    size_t pancakesCount, cookersCount;
    std::cin >> pancakesCount >> cookersCount;
    
    std::vector<size_t> cookerTimes(cookersCount);
    for(size_t i = 0; i < cookersCount; i++) {
        std::cin >> cookerTimes[i];
    }
    
    size_t min = 0;
    size_t max = pancakesCount * cookerTimes[0];
    size_t solution = max;
    
    while(min <= max) {
        size_t mid = min + (max - min) / 2;
        size_t possibleCooked = possibleCookedForTime(cookerTimes, mid);
        
        if(possibleCooked >= pancakesCount) {
            max = mid - 1;
            solution = mid;
        }
        else if(possibleCooked < pancakesCount) {
            min = mid + 1;
        }
    }
    
    std::cout << solution;
    
    return 0;
}