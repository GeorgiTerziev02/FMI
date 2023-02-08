#include <cmath>
#include <queue>
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

void print_odd_layers(Node* root) {
    std::queue<Node*> toProcess;
    toProcess.push(root);
    
    size_t currentLevel = 1;
    while(!toProcess.empty()) {
        size_t levelLength = toProcess.size();
        
        while(levelLength > 0) {
            Node* current = toProcess.front();
            toProcess.pop();
            
            if(currentLevel & 1) {
                std::cout << current->value << " ";
            }
            
            if(current->left) {
                toProcess.push(current->left);
            }
            if(current->right) {
                toProcess.push(current->right);
            }
            
            levelLength--;
        }
        
        currentLevel++;
    }
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

Node* remove(Node* current, size_t value) {
    if(!current) {
        return nullptr;
    }
    
    if(current->value > value) {
        current->left = remove(current->left, value);
    }
    else if(current->value < value) {
        current->right = remove(current->right, value);
    }
    else {
        if(!current->left && !current->right) {
            return nullptr;
        }
        if(!current->left) {
            return current->right;
        }
        if(!current->right) {
            return current->left;
        }
        
        Node* iter = current->right;
        
        while(iter->left) {
            iter = iter->left;
        }
        
        current->value = iter->value;
        current->right = remove(current->right, iter->value);
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
        else if(command == "print_odd_layers") {
            print_odd_layers(root);
        }
        else if(command == "remove") {
            size_t value;
            std::cin >> value;
            
            root = remove(root, value);
        }
    }
    
    return 0;
}
