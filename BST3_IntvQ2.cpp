/* 1.
2 sum in a BST
 is there a piar in BSt that sum upto a target value

 brute force is the first approach
 but it wil be nearly equal to [O(n^2)];
 say ek node value pakad liya ; or search kr liya 
 ki (target-nodeValue) hai ki nhi in the subtrees;


 but we need it in O( N) that is single traversal
 how? we know inorder traversal property of a binary tree
 which gives sorted values of the BST
 Now use two pointer method 

*/

void inorderSave(Node* root , vector<int> &inorder){
    if( root == NULL)   return;

    inorderSave(root -> left, inorder );
    inorder.push_back(root -> data);
    inorderSave(root -> right, inorder );

}

bool twoSumInBST(Node* root , int target){
    vector<int> inorder;
    bool ans = false;

    inorderSave(root, inorder);

    int j = 0;
    int k = inorder.size() - 1;
    while( j < k){
        if( inorder[j] + inorder[k] == target){
            ans = true;
        }
        else if( inorder[j] + inorder[k] < target){
            j++;
        }
        else {
            k++;
        }
    }

    return ans;
}

/* 2.
Flatten BST to a sorted LL
 store inorder in vecotr<Node*>
 now traverse and make right null and left to next dataNode
 akhir node ke dono pointers null hi lagane hai

 2.
 store node values in vector<int>
 nake a starting node and same cheez iske bad karte jao
 that is form a LL


*/

void inorderSave(Node* root, vector<int> &inorder){

}
Node* flattenToLL(Node* root ){

    vector<int> inorder;
    // store inorder that is sorted values
    inorder = inorderSave(Node* root);
    int n = inorder.size();

    Node* newRoot = new Node(inorder[0]);

    Node* curr = newRoot;

    for( int i = 1; i < n ; i++){
        Node* temp = new Node( inorder[i]);

        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;

    }
    // last node ko bothe pointers ko null krna hai
    curr -> left = NULL;
    curr -> right = NULL;

    return newRoot;

}

/*
Normal BST to Balanced BST
 for every node:  heightofleft - headofright <= 1;
 
 approach:
 inorder traverse krke 
 usse ek balanced BST bna denge


*/
void inorderSave(Node* root , vector<int> &inorder){
    if( root == NULL)   return;

    inorderSave(root -> left, inorder );
    inorder.push_back(root -> data);
    inorderSave(root -> right, inorder );

}

Node* inorderToBST(int s, in e, vector<int> &inorder){
    //base case
    if( s > e)  return NULL;

    int mid = s+e / 2;
    Node* root = new Node(inorder[mid]);
    root -> left = inorderToBST( s, mid - 1, inorder);
    root -> right = inorderToBST( mid + 1, e, inorder);
    return root;
}

Node* toBalancedBST(Node* root ){
    vector<int> inorder;
    inorderSave(root, inorder);

    return inorderToBST(o, inorder.size()-1, inorder);

} /// bina by reernce pass kiye TLE mar rha tha TC is O( n ) SC si O(n )

/*
BST from Preorder
 Approach1:


 Approach2:


 Approach3:
  har node ki range of values depend in parentNode values
  root node has range from -inf to inf 
  see BST_INVQ1 file
  

*/