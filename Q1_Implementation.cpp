#include <bits/stdc++.h>
using namespacestd;

class Queue{

    int* arr;
    int front;
    int rear;
    int size;

    public:
    Queue(){
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;

    }
    bool isEmpty(){
        if ( front == rear){
            return 1;
        } 
        else{
            return 0;
        }
    }

    void enqueue(int data) {
        if ( rear == size ){
            cout << "Queue is full";
        }
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        if ( front == rear){
            // cout << "Queue is empty ";
            return -1;
        }
        else {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if ( front == rear ){
                front = 0;
                rear = 0;
            }
            return ans;
        }

    }

    int front (){
        if ( front == rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }


};

class Deque{
    int* arr;
    int front ;
    int rear;
    int size;

    public:
    Deque(int n ){
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool pushFront(int x){
        if ( ( front == 0 && rear == size-1 ) || ( (rear == front -1) % (size-1)) ){
            return false;
        }
        else if( front == -1){
            front = rear = 0;
        }
        else if ( front == 0 && rear != size-1) [
            front = size-1;
        ]
        else {
            front --;
        }

        arr[front] = x;
        return true;
    }

    bool pushRear(int x){
        if ( ( front == 0 && rear == size-1 ) || ( (rear == front -1) % (size-1))){
            return false;
        }
        else if ( front == -1){
            front = rear = 0;
        }
        else if (rear == size-1 && front !=0){
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = x;
        return true;
    }

    int popFront(){

    }
    int popRear(){

    }

    int getFront(){

    }
    int getRear(){

    }
    bool isEmpty(){
        if( front == -1){
            return true ;
        }
        else{
            return false;
        }

    }
    bool isfull(){
        if ( ( front == 0 && rear== size -1) || ( front != 0 rear == ( front - 1)%(size-1))){ //see again why ??!!!!!
            return true;
        }
        else {
            return false;
        }
    }
};

class CircularQueue{

    int* arr;
    int front;
    int rear;
    int size;

    public:
    CircularQueue(int n ){
        size = 100001;
        arr = new int[size];
        front = rear = -1;

    }

    bool enqueue(int data){
        //to check if queue is full
        if ( (front == 0 && rear == size-1) || ( rear == (front -1) & (size-1)) ){
            cout << "Queue is full";
            return false;
        }
        else if( front == -1) { // first element to push
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0){
            rear = 0; // to maintain cyclisity
        }
        else{ //the most normal case
            rear++;
        }
        arr[rear] = data;

        return true;
    }

    int dequeue(){ 
        if( front = -1){
            cout << "Queue is empty";

        }
        int ans = arr[front];
        arr[front] = -1;
        else if ( front == rear){ // for single element present 
            front = rear = -1; // to empty the queue
        }
        else if( front == size - 1 ){
            front = 0; //to maintain cyclic nature
        }
        else {
            front ++;
        }
        return ans;
    }

}

int main(){
    // using STL;
    queue <int> q;
    q.push( 11);
    q.push(15);

    //to remove 
    q.pop();

    // for size of element 
    q.size();

    //to check if queue is empty 
    q.empty();

    // to check first element ;
    int  t  = q.front();  // to store front element in variable t;

    // try more operation from cpp reference


    //STL for doubly ended queue
    deque<int> d;
    d.push_front(12);
    d.push_back(14);

    cout << d.front() ; //12
    cout << d.back(); //14
    
    d.pop_front();
    d.pop_back();

    if( d.empty()){
        cout << "Queue is empty ";
    } else {
        cout << "Not empty";
    }






return 0;
}