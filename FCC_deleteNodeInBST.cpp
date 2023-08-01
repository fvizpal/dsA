/*
case 1: node with No CHILD
 its a leaf element
 simply delete the reference and then the node
*/

/*
case 2: node with one child
 delete the node
 and connect its child to the parent of the node
*/

/* 
case 3: node with  2 children
 this is tricky
 coz we will loose elements if we link one but not the other 
 we wil deal with such by reducing case 3 to 2 the to 1

*/

class Node* Delete(struct Node* root, int data){ // here data is the value to be deleted
    if ( root ==NULL) return root;

    else if ( data < root ->data) 
        root -> left = Delete(root -> left, data);
    else if ( data > root ->data) 
        root ->right = Delete(root -> right, data);
    else{ // to be deleted has been found 
        // case 1:
        if ( root -> left == NULL && root -> right == NULL){
            delete root;
            root = Null;
        }

        //case 2:
        else if ( root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if ( root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        //case 3:
        else{
            Node* temp = findMin(root->right); // say this findMin() will give us the min value in the right subtree
            root->data = temp->data;
            root->right = Delete( root->right, temp->data);
        }
    }

    return root; // we need to returnthsi root in all cases
}

