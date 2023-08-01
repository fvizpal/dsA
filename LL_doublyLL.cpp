#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node *prev;
    Node *next;

    //condtructor
    Node( int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;

    }

    //deconstructor
    ~Node(){
        int val = this -> data;
        if ( next != NULL){
            delete next;
            next = NULL;
        }
        cout << " memory free for node with data " << val << endl;
    }
};

void insertAtHead(Node* &tail,Node* &head, int d){
    if ( head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    } // do we need to update tail necessarily
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp ;
        head = temp ;
    } 
}

void insertAtTail(Node* &tail, Node* &head, int d){

    if ( tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp ;
        temp -> prev = tail;
        tail = temp ;
    }
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d ){

    //insert at start
    if (position == 1){
        insertAtHead( tail, head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while( cnt < position - 1){
        temp = temp -> next;
        cnt++;

    }

    //inserting at last
    if (temp -> next == NULL){
        insertAtTail( tail ,head, d);
        return;
    }

    //creating a node
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert; // temp k next ka previosu
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp; 

}

//traverse
void print ( Node *head){
    Node* temp = head;

    while ( temp != NULL){
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
    cout << endl;
}

//gives length
int getLength( Node *head){
    int len= 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    
    return len;
}

void deleteNode( int position, Node* &head ){ // generally tail ain't that important and we are fine with head only

    //deleting first node
    if ( position == 1){

        Node* temp = head;
        temp -> next -> prev = NULL;

        head = temp -> next;
        //memory free of start node
        temp ->next = NULL; // pointer htana bhi zaruri hai before deleting 
        delete temp;

    }
    else{
        //deleting postion other that 1
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while( cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL; // same reason
        delete curr;

    }
}


int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(tail, head, 11);
    print ( head);
    // cout << getLength( head) << endl;
    
    insertAtTail(tail, head, 25 );
    print ( head);

    insertAtPosition( tail , head, 3, 100);
    print ( head);

    deleteNode( 1, head);
    print ( head);
    // handle tail , after deletion of last element;


    return 0;
}