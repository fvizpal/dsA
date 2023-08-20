#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){ //constructor
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root){
    
    cout << "Enter data :" << endl;
    int data ;
    cin >> data;
    root = new Node(data);

    if ( data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left " << data << endl;
    root -> left = buildTree( root -> left);
    cout << "Enter data for inserting in right " << data << endl;
    root -> right = buildTree( root -> right);
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty){
        Node* temp = q.front();
        q.pop();

        if ( temp = NULL){// purana level complete ho chuka hai
            cout << endl;
            if(!q.empty()){ //queue still has some child nodes
                q.push(NULL);
            }
        } 
        else {
            cout << temp -> data << " ";    
            if ( temp -> left){ // agar not NULL hai
                q.push(temp -> left);
            }
            if ( temp -> right){ // q ka right agar not NULL hai 
                q.push(temp -> right);
            }
        }
    }
}

void inorder(Node * root){ //recursively
    //base case
    if ( root == NULL){
        return;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(Node* root){
    //base case
    if ( root == NULL){
        return;
    }
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(Node* root){
    //base case
    if ( root == NULL){
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

Node* buildFromLevelOrder( node* root){
    queue<Node*> q;
    cout << "Enter data for root " << endl;
    int data;
    cin >> data;
    root = new Ndoe(data);

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp -> data << endl;
        int leftData;
        cin >> leftData;

        if( leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node for " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if( rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}

int main (){
    Node* root = NULL;
    
    //creating a tree
    root = buildTree(root);

    //level order traversal of a tree
    levelOrderTraversal( root);
    
    return 0;
}
