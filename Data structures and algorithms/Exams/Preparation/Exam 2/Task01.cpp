void SinglyLinkedList::removeAll(int X)
{
    Node* prev = nullptr;
    Node* iter = head;
    while(iter){
        if(iter->value == X){
            if(prev) {
                prev->next = iter->next;
            } else {
                head = head->next;
            }
            
            iter = iter->next;
            continue;
        }
        
        prev = iter;
        iter = iter->next;
    }
}