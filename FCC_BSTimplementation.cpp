#include<iostream>
using namespace std;

class Node{ // the node for our binary search tree
    public:
    int data;
    Node* left;
    Node* right;

};

Node* createNewNode(int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;

    return newNode;
}

void insertNode(Node* &root,int data){ // to insert a node in  the tree // but before we need to create a new node in the dynamic memory
    if(root == NULL){
        // i.e. empty tree // for non empty tree ther will be
        // two cases : if smaller then in left else right sub tree insertion 
        root = createNewNode(data);
    }
    else if ( data <= root -> data){
        root -> left = insertNode(root -> left, data);
    }
    else {
        root -> right = insertNode(root -> right, data);
    }
}

bool search(Node* root , int data){
    if( root == NULL ){
        return false;
    }

    else if( root -> data) return true;
    else if ( data <= root -> data) return search(root -> left,data);
    else return search(root -> right , data);

}

int findMin(Node* root){
    // we have two aproaches a simple loop that is iterative solution
    // or a recursive solution 

    // first the iterative solution
    // we just need to go most left possible
    if ( root == NULL){
        return -1; // that is an error
    }

    Node* curr = root;
    while ( curr -> left != NULL){
        curr = curr -> left;
    }
    return curr->data; // actually we do not even need curr pointer using just root wld do 
                        // since we arent making any changes to our main root 

}
//the recursive solution to finding min element
int findMin(Node* root){
    if( root == NULL){
        return -1;
    }

    //base case
    else if ( root -> left ==NULL){
        return root -> data;
    }
    //serch in left part of BST
    return findMin(root -> left);
}
// to mind max its similar but just keep going right
ind findMax(Node* root)


/*
Finding HEIGHT of a tree
 number of edges in the longest path of a tree
 height is the maxx depth(no. of edges form root to that node) of a tree

 approach
    find height of left subtree and right tree
    take the max of both and add 1 to get the height of the tree

*/
int findHeight( Node* root){
    if ( root == NULL){
        return -1;  // think about why not 0 or -2 // 
    }
    return max(findHeight(root -> left), findHeight(root-> right))+1 ;
} // er... not understood



int main(){
    Node* root = NULL; // creating an empty tree 
    // this root is not the root for our tree but is only a pointer to th same
    
    insertNode(root, 15);
    insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 25); // try recursive tree for this one 
 
    //asking for a number and searching for it 
    int number ;
    cin >> number;
    if(search(root, number)) cout << "found\n";
    else cout << "not found \n";



    return 0;
}