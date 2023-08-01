#include<bits/stdc++.h>

class Node{ // the node for our binary search tree
    public:
        int data;
        Node* left;
        Node* right;

};

/*
LEVEL ORDER TRAVERSAL of the binary tree
 clearly we cannot just do it with one node
 we need to go back a level to go right  of an element 
 so what we can do is we can keep refernce of all its(the node we are at) cildren in a queue
 
 space complexity will be more
 TC - O(n)
 sc - O(n) worst and avg case and O(1) for best case
*/

void levelOrderTraversal(Node* root){
    if ( root ==NULL){
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    // while there is at least one discovered node
    while(!q.empty()){
        Node* curr = q.front();
        cout << curr -> data << " ";
        if(curr -> left != NULL ) q.push(curr -> left);
        if ( curr -> right != NULL ) q.push(curr -> right);
        q.pop(); //remove the element at front

    }
}

/*
DEPTH FIRST ALGOS  // see time 7:17:00
 recursion shall be used // see dis

 O(n) TC
 O(h) where h is height is SC
 in worst case SC= O(n)  in best or avg case SC is O(log n) 
*/

//PREORDER TRAVERSAL
void preorder(Node* root){
    if( root == NULL){ // this checks if address is not NULL 
        return ;        // that is a node exists
    }

    cout << root -> data <<" "; //D
    preorder(root -> left); //L
    preorder(root -> right); //R

}

// INORDER TRAVERSAL
void inorder(Node* root){
    if( root == NULL){
        return ;
    }

    inorder(root -> left); //L
    cout << root -> data <<" "; //D
    inorder(root -> right); //R

}

//POSTORDER TRAVERSAL
void postorder(Node* root){
    if( root == NULL){
        return ;
    }

    postorder(root -> left); //L
    postorder(root -> right); //R
    cout << root -> data <<" "; //D

}


int main (){

    return 0;
}