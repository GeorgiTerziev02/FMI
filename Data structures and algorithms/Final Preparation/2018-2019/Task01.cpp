#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Node {
    size_t value;
    Node* left, *right;
    
    Node(int value, Node* left = nullptr, Node* right = nullptr) {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

void print(Node* current) {
    if(!current) {
        return;
    }
    
    std::cout << current->value << " ";
    print(current->left);
    print(current->right);
}

Node* insert(Node* current, size_t value) {
    if(!current) {
        return new Node(value);
    }
    
    if(current->value > value) {
        current->left = insert(current->left, value);
    }
    else if(current->value < value) {
        current->right = insert(current->right, value);
    }
    
    return current;
}

int main() {
    size_t commandsCount;
    std::cin >> commandsCount;
    
    Node* root = nullptr;
    
    for(size_t i = 0; i < commandsCount; i++) {
        std::string command;
        std::cin >> command;
        
        if(command == "add") {
            size_t value;
            std::cin >> value;
            
            root = insert(root, value);
        }
        else if(command == "print") {
            print(root);
        }
    }
    
    return 0;
}
