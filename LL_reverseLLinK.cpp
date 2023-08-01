#include<iostream>
using namespace std;

Node* kReverse(Node* head, int k){
    
    //base  call;
    if ( head == NULL){
        return NULL;
    }

    //step 1 : first reverse k node
    Node* next == NULL;
    Node* curr == head;
    Node* prev == NULL;
    int cnt = 0;

    while( curr != NULL && cnt < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    //step 2 : recursion dekhlega aage ka
    if ( next != NULL){
        head -> next = kReverse(next, k);
    }

    //step3: return head of reversed list 
    return prev;
}






int main(){




    return 0;
}