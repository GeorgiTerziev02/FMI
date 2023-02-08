#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *next;
    int data;
    
    Node() {}
    
    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

class LinkedList{
    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList(){
        Node* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value){
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        
        if (head == nullptr and tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    
    // wrote by me
    void pushFront(int value) {
        Node* temp = new Node(value);
        
        if(!head && !tail) {
            head = tail = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
    }
    
    void print(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    
    Node *head, *tail;
};

// wrote by me
void solve(LinkedList& num1, LinkedList& num2){
    Node* iter1 = num1.head, *iter2 = num2.head;
    
    int carry = 0;
    LinkedList result;
    while(iter1 && iter2) {
        int currentSum = iter1->data + iter2->data + carry;
        currentSum > 9 ? carry = 1 : carry = 0;
        
        result.pushFront(currentSum % 10);
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    
    while(iter1) {
        int currentSum = iter1->data + carry;
        currentSum > 9 ? carry = 1 : carry = 0;
        
        result.pushFront(currentSum % 10);
        iter1 = iter1->next;
    }
    
    while(iter2) {
        int currentSum = iter2->data + carry;
        currentSum > 9 ? carry = 1 : carry = 0;
        
        result.pushFront(currentSum % 10);
        iter2 = iter2->next;
    }
    
    if(carry > 0) {
        result.pushFront(carry);
    }
    
    Node* iter = result.head;
    while(iter) {
        std::cout << iter->data;
        iter = iter->next;
    }
}

int main(){
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for(int i = 0 ; i < size1 ; i++){
        int digit;
        cin >> digit;
        num1.add(digit);
    }
    
    cin >> size2;
    for(int i = 0 ; i < size2 ; i++){
        int digit;
        cin >> digit;
        num2.add(digit);
    }
  
    solve(num1, num2);
}