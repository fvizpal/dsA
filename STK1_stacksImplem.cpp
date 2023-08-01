
// using STL
// #include<stack>
#include<iostream>

// int main (){

//     //creation 
//     stack<int> s;

//     //adding an element;
//     s.push(2);
//     s.push(4);

//     //to remove 
//     s.pop();
//      to look at top element ;
//      cout << s.top();

//      return 0;    
// }

//IMPLEMENTATION
class Stack{
    //properties
    public:

    int* arr ;
    int top;
    int size;

    //behaviour
    Stack( int size ) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push( int element){
        if( size - top > 1){
            top++;
            arr[top] = element;

        } else {
            cout << "Stack verflow" << endl;
        }
    }

    void pop(){
        if ( top >= 0){
            top--;
        } else {
            cout << "Stack Underflow";
        }
    }

    void peek(){
        if ( top >= 0){
            return arr[top];
        } else {
            cout << "Stack is empty";
        }
    }

    bool isEmpty() {
        if ( top == -1){
            return true;
        } else {
            return false;
        }
    }

};

int main(){
    
    Stack st(5)
}