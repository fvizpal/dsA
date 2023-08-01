
Node* uniqueSortedList(Node* head){

    //empty list
    if(head == NULL)
        return Null;
    
    //Non empty list

    Node* curr = head;

    while(curr != NULL){

        if(curr -> next != NULL && curr -> data == curr -> next -> data){
            Node* next_next = curr -> next -> next;
            Node* nodeToDelete = curr -> next;
            delete(node ToDelete); // agar pehle hi pointer ko hatta denge to next delete hone wale pointer ka track nhi rhega isliye first delete

            curr -> next = next_next;
        }
        else{ //not equal
            curr = curr -> next;
        }
    }

    return head;
}