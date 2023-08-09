/*
sum of the longest bloodline of a tree
 sum from a root to a leaf of the longest path from root to leaf
 
 we ll do this via recursion

*/
void solve( Node* root, int sum , int &maxSum, int len, int &maxLen){
    //base case
    if( root == NULL){
        if( len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if( len == maxLen){
            maxSum = max( sum , maxSum);
        }
        return;
    }

    sum += root -> daat;

    solve( root -> left, sum , maxSum, len+1, maxLen);
    solve( root -> right, sum , maxSum, len+1, maxLen);

} //TC is O(n) since each node is visted only once Sc is O(h)
int sumOfLongRootToLeafPath(Node* root){
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = 0;

    solve( root, sum , maxSum, len , maxLen);

    return maxSum;
}

/*
Lowest common ancestor (lca)
 self explaintory question

 approach
  root se lekar ek leaf tak ka path nikale for two relevent
  then see the common path ... the common nodes will be the common ancestors

*/

Node* lca(Node* root , int n1, int n2){
    //base case
    if( root == NULL){
        return NULL;
    }
    if( root -> data ==  n1 || root -> data ==n2){
        // bhai agar tu equal h n1 ya n2 ke toh return krde apne aap ko
        return root;
    }

    Node* leftAns = lca( root -> left, n1, n2);
    Node* rightAns = lca( root -> right, n1, n2);

    if( leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if( leftAns != NULL && rightAns == NULL ){
        return leftAns;
    }
    else if ( leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return NULL;
    }
    
} //TC is O(n) and SC is O(h)

/*
K sum path
 given a value of k and binary tree
 return all paths which give the sum of node value equal to this K 
 
 approach
  mai har ek node p ek vector m uss tak ka path bnate jaunga or 
  uska sum ocmpare krte jaunga K ke sath

*/

void solve( Node* root , int k, int &count, vector<int> path){
    //base case
    if( root == NULL){
        return;
    }
    path.push_back( root -> data); // vector m jis node p khade hn uska data daal rhe hn

    //left
    solve( root -> left, k, count , path);
    //right
    solve( root -> right, k, count , path);

    //check for k sum
    int size = path.size();
    int sum = 0;
    for( i = size-1; i >= 0; i--){
        sum += path[i];
        if( sum == k){
            count++;
        }
    }
    path.pop_back();// last wale ko hatane k liye
}// TC is hw

int sumK(Node* root , int k){
    vector< int > path;
    int count = 0;

    solve( root , k , count , path);

    return count;
}

/*
Kth ancestor in a tree
 approach
  there are two approaches to solve the question
  one is using recursion
  and the other si your hw
  jese jese uppar jata ja rha hu k-- krta jarha hu 

*/
void solve(Node* root , int &k, int node){
    //base case
    if( root == NULL){
        return null;
    }
    if( root -> data == node){
        return root;
    }

    Node* leftAns = solve( root -> left, k, node);
    Node* rightAns = solve( root -> right, k, node);

    if( leftAns != NULL && rightAns == NULL){
        k--;
        if( k <= 0 ){
            //to lock the ans
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    else if ( leftAns == NULL && rightAns != NULL){
        k--;
        if( k <= 0){
            // answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int kAncestor(Node* root, int k, int node){
    Node* ans = solve( root , k , node);

    if ( ans == NULL || ans -> data ==node) { // this is handling a special node
        return -1;
    }
    else {
        return ans -> data;
    }
} //TC is O(n) and SC is O(h)


/*
Maximum sum of Non - adjacent nodes
 given a tree | aap max sum nikalo | But you cannot use connected nodes
 in sabhi sums m jo maximum h usse return krna h 

 approach
    <a , b> type ka pair rakhenge 
    a will be the sum including the node value and
    b will be excluding it
*/

pair<int , int > solve( Node* root ){
    //base case
    if( root == NULL){
        pair< int , int > p = make_pair(0,0);
        return p;
    }

    pair< int , int > left = solve(root -> left);
    pair< int , int > right = solve(root -> right);

    pair<int , int> res;
    res.first = root -> data = left.second + right. second;

    res.second = max( left.first, left.second) + max(right.first , right.second);

    return res;
}

int getMax( Node* root){

    pair < int , int> ans = solve ( root );
    return max( ans.first, ans.second);
} // TC is O(n) SC is O(h)
