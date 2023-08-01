bool isSubtreeLesser(Node* root, int value){ // than this value
    if(root == NULL) retun true;
    if(root -> data <= value
        && isSubtreeLesser(root->left, value)
        && isSubtreeLesser(root-> right, value))

        return true;
    else
        false
    // or we can do is find max in left and min in right and
    // see if it is less than the root data
}

bool isSubtreegreater(Node* root, int value){
    if(root == NULL) retun true;
    if(root -> data > value
        && isSubtreeLesser(root->left, value)
        && isSubtreeLesser(root-> right, value)){

        return true;
    }
    else{
        false
    }
}

bool isBSTUtil(Node* root , int minValue, int maxValue){ // see this at 7:38:00
    if ( root ==NULL) return true;

    if( root -> data < minValue && root-> data > maxValue 
        && isBSTUtil(root -> left,  minValue, root -> data)
        && isBSTUtil(root -> right , root -> data, maxValue))
            return true;
    else 
        return false;
}
bool isBinarySearchTree(Node* root){
    if (root == NULL) return true
    // all the elements in left subtree should be lesser
    // and all in right subtree should be greater
    if(isSubtreeLesser(root -> left, root -> data)  // or here what we can do is compare this with a range of max value and 
        && isSubtreegreater(root -> right, root-> data) // min value that would be done in a constant time
        && isBinarySearchTree(root->left) // see 7:39:00
        && isBinarySearchTree(root->right)) 
        return true;
    else 
        return false;

    //OR
    return isBSTutil(root,INT_MIN,INT_MAX); // will have even less TC O(n) and SC is O( h )
    
    // but here duplicates have not been handlede
    // another way : perform inorder traversal and see if it gives sorted data

}