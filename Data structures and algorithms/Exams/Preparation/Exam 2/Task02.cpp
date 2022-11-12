int SinglyLinkedList::count(int X)
{
    int result = 0;
    Node* iter = head;
    while(iter){
        if(iter->value == X)
            result++;
        
        iter = iter->next;
    }
    
    return result;
}