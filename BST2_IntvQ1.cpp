/*
Validate BST
 is a tree BST or not
 for every node the left subtree will have smaller values in node
 and right subtree has greater value than node
 inorder traversal gives sorted values


 Approach 1:
    see FCC
*/



/*
Find Kth smallest element or Kth largest element( just count till n-k+1)
 
 Approach
  inorder traversal is sorted 
  then k th element ffrom beginning
  of that sorted list ontained from traversal

  ya ek counter lga lenge inorder traversal k sath
  jese hi K ke equal hua counter ; stop


*/
int solve(Node* root, int &i, int k){
    //base case
    if( root == NULL){
        return -1;
    }

    int left = solve(root -> left, i, k);

    if( left != -1){
        return left;
    }

    //N
    i++;
    if( i==k)  return root -> data;

    // R
    return solve(root -> right, i, k);


}
int kSmallestElement(Node* root, int k){
    int i = 0;
    int ans = solve(root , i, k);

    return ans;
} // TC is o( n) ans SC is O(h)

// optimitation
// can be done using Morris Traversal


/*
Predecessor and successor in BST
 Inorder predecessor or succeseeor btana hai

 mtlb ye ki inorder traversal krenge to kisi node ki value ke pehle wali or bad wali value btani h
 
 //OPTIMISATION k liye use MORRIS TRAVERSAL
   
*/

pair< int ,int> predecessorSuccessor(Node* root, int key ){
    //find key 
    Node* temp = root;
    int pred = -1;
    int succ = -1;

    while( temp -> data != key){

        if( temp -> data > key){
            succ = temp -> data;
            temp = temp -> left;
        }
        else{
            pred = temp -> data;
            temp = temp -> right;
        }
    }

    //pred ans succ
    Node* leftTree = temp -> left;
    while( leftTree != NULL){
        pred = leftTree -> data;
        leftTree= leftTree-> right;
    }

    //succ
    Node* rightTree = temp -> right;
    while( rightTree != NULL){
        succ = rightTree;
        rightTree = rightTree->left;
    }

    pair<int , int> ans = make_pair(pred,succ);

    return ans; // or return {pred, succ};

}   // TC is O(n) ans SC is O(1);

/*
LCA in a BST
 that is lowest common ancestor
 to nodes
 similar to BT
 but here approach shall be different bcoz BST has its properties

 jha pr rootData > a && rootdata < b
 or ( iska ulta )   whi LCA hai


*/
Node<int>* LCAinaBST( Node* root, Node* P, Node* Q){
    //base case
    if( root == NULL){
        return NULL;
    }

    // while( root != NULL){
    //     if( root -> data < P->data && root ->data < Q-> data)
    //         root = root -> right;
        
    //     else if( root -> data > P->data && root ->data > Q-> data)
    //         root = root -> left;
    //     else  return root;
    // }  
    // This is the ITERATIVE TAREEKA ; this saves space O(1)


    if( root -> data < P->data && root ->data < Q-> data){
        return LCAinaBST( root -> right, P, Q);
    }

    if( root -> data > P->data && root ->data > Q-> data){
        return LCAinaBST( root ->left, P, Q);
    }

    return root;
} // TC is O(n) SC is O(h)


/*
BST from a PREORDER
 givrn an array with elemnts in an order pre post or in 
 and be nned to create a BST

 Approach
  just insert karo usinh the insert function we created here TC would be O(n^2)

  other more optimized approach would be ; 
  since we are given a preorder we can sort it to get an inorder data array
  now uisng this inorder and preorder we can create a BT 
  as we saw in our previous ques videos of BT 
  TC O(nlogn) hogi 

  approach 3
  we know preorder is NLR ;; start from intmin and run till intmax
  the root nide value can have range from -inf to inf 
  but all other node values depend on values of parent node

*/

Node* solve( vector<int> &preorder, int mini, int maxi, int &i){
    if( i> preorder.size()){
        return NULL;
    }

    if( preorder[i] > maxi || preorder[i] < mini )   return NULL;

    Node* root = new Node(preorder[i++]);
    root -> left = solve( preorder, mini, root-> data, i);
    root -> right = solve( preorder, root-> data, maxi, i);

    return root;
}

Node* preorderToBST( vector<int> &preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;

    int i = 0;
    return solve(preorder, mini , maxi, i);
} // TC is O( n )
// but yha mini ki zaroorat hi nhi hai //




