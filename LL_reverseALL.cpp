#include<bits/stdc++.h>
using namespace std;

// THE ITERATIVE SOLUTION 
void reversedLL(Node* &head){
    if ( head == NULL || head -> next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while( curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

//recursive solution
void recReversedLL( Node* &head, NOde* curr, Node* prev){
    // in the main()
    // Node* curr = head;
    // Node* prev = NULL;
    
    //base case
    if ( curr == NULL){
        head = prev;
        return;

    }

    // recursive relatiojn
    Node* forward = curr -> next;
    recReversedLL( head , forward, curr)
    curr -> next = prev;

}

//Another recursive relation
//it will return head of the reveerse list
void recursiveLL(Node* &head){

    //base case
    if ( head == NULL || head -> next ==NULL){
        return head;
    }

    Node* chotaHead = recursiveLL( head -> next );

    head -> next -> next = head;
    head -> next =NULL;

    return chotaHead;
}

int main(){




    return 0;
}