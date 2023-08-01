/*
Height of a binary tree
 given a binary tree 
 we need to gfind its height
 or the longest path between root node 
 and a leaf node
 expected TC and SC are O(n)

 approach:
  recursion bhaiya will do it smoothly
  maximum of height of left sub tree and right subtree
  then adding 1 for the root node
  will give complete height
  even heights of subtree will be given by recursion bhaiya
*/ 

int Height ( Node* root){
    //base case
    if( root == NULL){
        return 0;
    }

    int left = Height(root -> left); // shouldnt the data tyoe be node*
    int right = Height( root -> right); // here too

    int ans = max( left , right) + 1;
    return ans;
} //TC O(n) & SC O(h) height

/*
Diameter of a binary tree
 or called width
 it is the longest path between any two (end) nodes
 
 answer may be in left subtree only 
 or in right only or in combo

*/

int Diameter( Node* root){
    // base case
    if ( root == NULL){
        return 0;

    }
    
    int op1 = Diameter(root ->left);
    int op2 = Diameter(root -> right);
    int op3 = Height(root ->left) + Height(root -> right) + 1;

    int ans = max( op1, op2, op3);
    return ans;
} //but here the TC becomes O(n^2)
// because height function is also being called in every run of diameter
// so at every node we are doung three things op#
// so to make it O(n) we need to remove height fnx
// Optimised soln
pair<int, int> diameterFast( Node8 root){
    // base case
    if ( root == NULL){
        pair<int, int > p = make_pair(0,0); //first is for diamter and second for height
        return p;
    }
    pair<int, int> left = diameterFast(root -> left);
    pair<int, int> right = diameterFast(root -> right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int , int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max( left.second, right.second) + 1;
    
    return ans;
    
}
int Diameter( Node* root){
    return diameterFast(root).first;
} //TC here is O(n) and SC is O(h)

/*
check for balanced tree
 that is difference of heights of left and right subtree is not more than one for all nodes

*/

bool isBalanced(Node* root){
    if( root == NULL){
        return true;
    }

    bool left = isBalanced(root ->left);
    bool right = isBalanced(root ->right);
    bool diff = abs( height( root -> left) - height(root -> right) ) <= 1;

    if( left && right && diff){
        return 1;
    } else {
        return false;
    }
}// but O(n^2) since we are calling height as well
// so here we go again
pair<bool, int> isBalancedFast(Node* root){
    if( root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<int,int> left = isBalancedFast(root -> left);
    pair<int,int> right = isBalancedFast(root -> right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs( left.second - right.second ) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second ) + 1;

    if( leftAns && rightAns && diff){
        ans.first = true;
    } else {
        ans.first = false;
    }

    return ans;
}
bool isBalanced(Node* root){
    return isBalancedFast(root).first;
}

/*
Identical Trees 
 check if two tree are identical or not
 recursion firse 
 node ki value compare kro - if true then do same for left and right 
 subtrees if not return false

*/
bool isIdentical(Node* root1, Node* root2){
    //base case
    if( root1 == NULL && root2 == NULL){
        return true;
    }
    if( root1 == NULL && root2 != NULL){
        return false;
    }
    if( root1 != NULL && root2 == NULL){
        return false;
    }

    bool left = isIdentical(root1 -> left, root2 -> left);
    bool right = isIdentical( root1 -> right, root2 -> right);

    bool  value = root1 -> data == root2-> data;

    if(left && right&& value){
        return true;
    } else {
        return false;
    }

} //TC is O(n) make recursive call stack to het SC

/*
Sum tree
 every Node's value should be equal to sum of values of left subtree
 and the right subtree for every node

 check the left subtree
 check the right subtree
 check current node

*/
pair <bool,int> isSumTreeFast(Node* root){
    //base case
    if( root == NULL){
        pair < bool , int> p = make_pair(true, 0); // node hi nhi h sum kha se niklega // isliye 0
        return p;
    }
    //leaf node ko check nhi krna hai // so pre defining what to give
    // this is leaf node
    if( root -> left == NULL && root -> right == NULL){
        pair <bool, int> p = make_pair(true, root -> data);
    }

    pair<bool, int> leftAns = isSumTreeFast(root ->left);
    pair<bool, int> rightAns = isSumTreeFast(root ->right);

    bool left = leftAns.first; // ye bta rha h if left subtree is sum tree
    bool right = rightAns.first;// ye bta rha h if right subtree is sum tree
    
    bool condn = root -> data == leftAns.second + right.second;

    pair<bool, int >  ans;
    if( left && right && condn){
        ans.first = true;
        ans.second = 2* root -> data; // nhi smjha
    } 
    else{
        ans.first = false;
    }
    return ans;
}
bool isSumTree(Node* root){
    
    return isSumTreeFast.first;
} // TC is O(n)