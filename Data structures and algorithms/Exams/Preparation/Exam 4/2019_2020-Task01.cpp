#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    long long n;
    std::cin >> n;
    
    priority_queue<long long, vector<long long>, greater<long long>> q;
    
    for(size_t i = 0; i < n; i++) {
        long long input;
        std::cin >> input;
        if(!q.empty() && input == -1) {
            std::cout << q.top() << " ";
            q.pop();
        } else if(input != -1) {
            q.push(input);
        }
    }
    
    return 0;
}