#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // constructor
    Node( int data){
        
        this -> data = data;
        this -> next = NULL;

    }

    //destructor
    ~Node(){
        int value = this -> data;
        //memeory free
        if( this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << " Mem free " << value << endl;
    }
};

void insertAtHead( Node* &head, int d){

    // creating new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

}
void insertAtTail( Node* &tail, int d){
    //create new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d){

    //insert at start
    if ( position ==1){
        insertAtHead(head, d);
        return; // return k bagair do bar dal ja rha tha 
    }
    //first we need to traverse to that position
    Node* temp = head;
    int cnt = 1;
    while( cnt < position - 1){ // third p dalne k liye 2nd node p phuchna h 
        temp = temp -> next;
        cnt++;
    }

    if ( temp-> next == NULL){ // i.e. last me
        insertAtTail(tail , d);
        return;
    }

    //creating new node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
    
}



void print ( Node* &head){

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }

    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;

    }
    cout << endl;
}

void deleteNode( int position, Node* &head ){ // generally tail ain't that important and we are fine with head only

    //deleting first node
    if ( position == 1){

        Node* temp = head;
        head = head -> next;
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

        prev -> next = curr -> next;
        curr -> next = NULL; // same reason
        delete curr;

    }
}

int main() {

    //creating new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
    //cout << node1 -> next << endl;

    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    //print(head);

    insertAtHead(head, 12);

    //print(head);

    insertAtTail(tail, 15);
    print ( head);

    insertAtPosition(tail , head, 3 , 22);
    print ( head); // but 1 posit p nhi dal pyega bcoz our code is such that we need orevious element so we need to give condition for that to 
    // last i.e. 4 p dalne p vese to dikkat nhi but tail needs to be updated

    deleteNode(4, head);
    print (head);

    return 0;
}