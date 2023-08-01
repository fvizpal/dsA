

bool floydLoopDetect(Node* head){
    if(head == NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){

        fast = fast -> next;
        if ( fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;

        if (slow == fast){ //ye milna kisi bhi node (which is part of loop) pe ho skta h

            return 1;
        }
    }

    return false;
}

//getting starting Node of a loop using floyds algo
Node* getStartLoopNode(Node* head){

    if ( head ==NULL){
        return NULL;
    }

    Node* intersection = floydLoopDetect(head);
    Node* slow = head;
    Node* fast = head;

    while ( slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow; 

}

void removeLoop(Node* &head){

    if ( head == NULL){
        return ;
    }

    Node* startOfLoop = getStartLoopNode(head);

    Node* temp = startOfLoop;
    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }
    temp -> next = NULL:
}

