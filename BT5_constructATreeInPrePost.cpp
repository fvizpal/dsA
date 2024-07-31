/* Construct a binary tree
 From Inorder(LNR) , preorder(NLR), postorder(LRN)
 
 given in input wld be these arrays in these orders
 output a binary tree

 . preorder ka first element would be the root  - we know
 . now the values to the LEFT of this corresponding root node value in inorder array
    wld be of left subtree and the right ones wld be of right subtree
 . now looking at the right subtree only we again look at corresponding right part of
    preorder array ; this part in preorder array wld give the root element of this 
    right subarray
 . repeat this process for all such subtrees found in both left and right directions

 ### in POST ORDER
 . 

*/
int findPosition( vector<int> inorder, int element){ // yha optimisation kar skte hai pehle se ek map banake bw index and inorder elements
    for( int i = 0; i < inorder.size(); i++){
        if( element == inorder[i]){
            return i;
        }
    }
    return -1;
}
Node* solve( vector<int> preorder, vector<int> inorder, int preIndex, int inStart, int inEnd){
    //base case
    if( preIndex >= preorder.size() || inStart > inEnd) {
        return nullptr;   
    }
    int element = preorder[preIndex++]; // preindex ko ek se bada diya hai
    Node* root = new Node(element);

    int position = findPosition(inorder, element);

    // the recursive calls

    root->left = solve(preorder, inorder, preIndex, inStart, position - 1 );

    root ->right = solve(preorder, inorder, preIndex, position + 1, inEnd);

    return root;
}

Node* buildTree(vector<int> preorder, vector<int> inorder){
    int preIndex = 0;
    unordered_map<int,int> nodeToIndex;
    createMapping(inorder, nodeToIndex); // make this function

    Node* ans = solve( preorder, inorder, preIndex, 0, n-1);

    return ans;
}

// given INORDER AND POSTORDER
TreeNode* solve(
                vector<int> &postorder, 
                int &ind, int left, int right, 
                unordered_map<int,int> &nodeind
    ){

    if( ind < 0 || left > right){
        return nullptr;
    }

    int element = postorder[ind];
    int position = nodeind[element];

    TreeNode* root = new TreeNode( element);
    ind--;
    root->right = solve( postorder,ind, position + 1, right, nodeind);
    root->left = solve(postorder, ind, left, position-1, nodeind);

    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> nodeind;
    for( int i = 0; i < inorder.size(); i++){
        nodeind[inorder[i]] = i;
    }
    int ind = postorder.size() - 1;
    return solve(postorder, ind, 0, inorder.size() - 1, nodeind);
}