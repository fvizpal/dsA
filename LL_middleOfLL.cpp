//even k case m do middle vale mese , right wla choose kr rhe hn


int getLength(Node* head){

    int len = 0;
    while( head != NULL){
        len ++;
        head = head -> next;
    }

    return len;
}

void middleOfLL(Node* &head){

    int len = getLength(head);
    int ans = ( len / 2 );

    Node* temp = head;
    int cnt = 0;
    while ( cnt < ans){
        temp = temp -> next;
        cnt++;
    }

    return temp;
}

// TC :  O(n) + O(n/2) = O(n)
// kya or kam m ho skta hai
