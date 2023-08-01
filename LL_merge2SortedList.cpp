
Ndoe* solve(Node* first, Node* second){
    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;
    
    while( next1 != NULL && curr2 != NULL){
        if( curr2 -> data >= curr1 -> data 
                && curr2 -> data <= next1 -> data){
            // this is the part if the data does lie in between 

            //adding node in between
            curr1 -> next = curr2;
            next2 = curr2 -> next; // so that track of remaining in secondList is not lost
            curr2 -> next = next1;

            //updating pointers 
            curr1 = curr2;
            curr2 = next2;
        }
        else{ // when it doesnt lie in between
            //curr1 and next1 ko aage bdhana hai
            curr1 = next1;
            next1 = next1 -> next;

            if( next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }

        }
    }
    
    return first;
}

Node* mergeLists(Node* first, Node* second){
    if ( first == NULL){
        return second;
    }
    if ( second == NULL){
        return first;
    }

    if ( first -> data <= second -> data){ // beacuse we in our accordance need first to be list with smaller firsst element
        return solve(first, second);
    }
    else{
        return solve( second, first);
    }

}