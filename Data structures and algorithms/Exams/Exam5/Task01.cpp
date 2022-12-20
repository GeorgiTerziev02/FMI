#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    char a1[500];
    char a2[500];
    cin.getline(a1, 500);
    cin.getline(a2, 500);
    string a(a1);
    string b(a2);
    
    unordered_map<string, size_t> container1;    
    unordered_map<string, size_t> container2;
    
    for(size_t i = 0; i < a.size(); i++){
        string current;
        while(a[i] != '\0' && a[i] != ' ' ){
            current += a[i];
            i++;
        }
        container1[current]++;
    }
    
    for(size_t i = 0; i < b.size(); i++){
        string current;
        while(b[i] != '\0' && b[i] != ' ' ){
            current += b[i];
            i++;
        }
        container2[current]++;
    }
    
    vector<string> res1;
    for(auto& kvp: container1){
        if(kvp.second == 1 && container2.count(kvp.first) == 0){
            res1.push_back(kvp.first);
        }
    }
    
    for(auto& kvp: container2){
        if(kvp.second == 1 && container1.count(kvp.first) == 0){
            res1.push_back(kvp.first);
        }
    }
    
    sort(res1.begin(), res1.end());
    
    for(size_t i = 0; i < res1.size(); i++){
        std::cout << res1[i] << '\n';
    }
    
    return 0;
}
