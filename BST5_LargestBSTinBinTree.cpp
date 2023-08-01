/*
Largest BST in a Binary tree
 Given a tree, whaat is the largest BST in that tree that can be seen
 -For every node left part has smaller value and the right part has greater value
 
 approach
    go on every node and check if it forms BST and keep track of max size
    isBST function se O(n) me pata chal jayega // this shall be our brute force approach

    optimised approach :
     we are calling isBST function for each node
     we shall not do that // rather if left subtree is BST and right subtree is also BST ;
     and the root value should be greater than maximum of left subtree and 
     smaller than right subtree minimum // then we are good
     is balanced BST me hamne kuch time bchaya tha vese hi

*/
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode<int>* root, int &ans){
    //base caase
    if( root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root -> data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if( left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    //answer update
    if( currNode.isBST){
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestBST( TreeNode<int>* root){
    int maxSize = 0;
    info temp = solve( root, maxSize);

    return maxSize;
}
// TC O(n) hoga; 