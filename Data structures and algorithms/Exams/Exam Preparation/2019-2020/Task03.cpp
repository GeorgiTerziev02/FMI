#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        
        if (head == nullptr && tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    
    pair<Node*, Node*> reverseLL(Node* start, size_t length) {
        Node* iter = start;
        Node* prev = nullptr, *next = nullptr;
        
        size_t currentIndex = 0;
        while(iter != nullptr && currentIndex < length) {
            next = iter->next;
            iter->next = prev;
            prev = iter;
            iter = next;
            currentIndex++;
        }
        
        return {iter, start};
    }

    // Where we write our code
    void reverse(int from, int to) {
        if(!head) {
            return;
        }
        
        int currentIndex = 1;
        Node* prev = nullptr;
        Node* temp = head;
        while(currentIndex < from && temp) {
            currentIndex++;
            prev = temp;
            temp = temp->next;
        }
        
        if(!temp) {
            return;
        }
        
        Node* tailOfReversed = temp;
        Node* prevStartOfReversed = prev;
        Node* next = nullptr;
        
        while(currentIndex <= to && temp) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            currentIndex++;
        }
        
        if(temp) {
            tailOfReversed->next = temp;
        }
        else {
            tail = tailOfReversed;
            tail->next = nullptr;
        }
        if(prevStartOfReversed) {
            prevStartOfReversed->next = prev;
        }
        else {
            head = prev;
        }
    }

    void print() {
        Node* temp = head;
    
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    
        cout << endl;
    }

    ~List() {
        Node* curr = head;
        
        while(curr) {
            Node* prev = new Node;
            prev = curr;
            curr = curr->next;
            delete prev;
        }
        
        delete curr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    List testList;

    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {
        
        string op;
        cin >> op;
        
        if (op == "add") {
            int num;
            cin >> num;
            testList.add(num);
        }
            
        if (op == "print") {
            testList.print();
        }
            
        if (op == "reverse") {
            int from, to;
            cin >> from >> to;
            testList.reverse(from, to);
        }
    }
    
    return 0;
}