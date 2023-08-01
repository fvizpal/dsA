// that is we need to find the node that would come 
// immediatly after the given node in INORDER traversal of the BST

// L - D - R // Inorder successor // O(n) is TC 
// note that this gives sorted data if done on a BST

class Node{
    int data;
    Node* left;
    Node* right ;
    // NOde* parent;
};

// function to find min element in a subtree
Node* FindMin(Node* root){
    if( root == NULL) return NULL;

    while( root -> left != NULL){
        root = root -> left;
    }
    return root;
}

//function to find successor
Node* getSuccessor( Node8 root, int data){
    // first we need to search for that data
    // say  find is the function for it
    Node* curr = find( root , data);
    if( curr == NULL) return NULL;
    // this cld have been avoided if we had directly the address in the arh=gument of the node to be worked with

    // case 1: Node has right subtree
    if( curr-> right != NULL){
        return FindMin(curr -> right );
    }

    // case 2:
    else{
        Node* successor = NULL;
        Node* ancestor = root;
        while( ancestor != curr){
            if( curr -> data < ancestor -> data){
                successor = ancestor; // so far this os the deepest node for which node is in left
                ancestor = ancestor -> left;
            }
            else{
                ancestor = ancestor -> right;
            }
        }
        return successor;
    }
} 
// this function has TC O(h) 
