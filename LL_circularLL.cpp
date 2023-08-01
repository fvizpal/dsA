#include<bits/stdc++.h>
using namespace std;
 

class Node{
    
    public:
    int data;
    Node* next;

    //condtructor
    Node( int d){
        this -> data = d;
        this -> next = NULL;

    }

    ~Node(){
        int value = this -> data;
        if ( this -> next != NULL){
            delete next;
            next = NULL;

        }
        cout << " memory freed for node with value " << value << endl;

    }

};

void insertNode( Node* &tail, int element, int d){
    // if empty list
    //an element is for comparison
    //assuming that the element is present in the lsit 
    if ( tail = NULL){
        Node* newNode= new Node(d);
        tail = newNode;
        newNode -> next = newNode;

    }
    else{
        //non empty list

        Node* curr = tail ;
        while ( curr -> data != element){
            curr = curr -> next;

        }
        //elemnt found - curr is in the elemnt wala node
        Node* temp =new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }
}

//traversing or printing the list
void print ( Node* tail ){ // WHY WE DO NOT NECESSARILY NEED TO USE REFERENCE HERE

    Node* temp = tail;

    //empty list 
    if ( tail == NULL){
        cout << "List is empty " << endl;
        return;

    }
    


    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    }while( tail != temp);
    cout << endl;

}

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}

bool isCircularList(Node* head){
    if (head == NULL){
        return true;
    }

    Node* temp = head -> next;
    while ( temp != NULL && temp != head){
        temp = temp -> next;

    }

    if ( temp == head ){
        return true;
    }
    
    return false;
}

bool detectLoop(Node* head ){
    if(head == NULL){
        return false;
    }
    map <Node*, bool> visited;

    NOde* temp = head;
    while(temp != NULL){
        
        if (visited[temp] == true){
            return 1;
        }
        visited[temp]= true;
        temp = temp -> next;
    }
    return false; 
}


int main (){

    Node* tail = NULL;

    //inserting in empty list
    insertNode( tail, 5, 3);
    print (tail);

    insertNode( tail , 3 , 5);
    print ( tail);


    return 0;
}