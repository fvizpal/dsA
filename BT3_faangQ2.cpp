/*
Zig Zag Traversal
 ek bar left to right order m data print krnge 
 then right to left ; then again left to right and sop on

 approach
  traversal k recursive and iterative traversal dekhe hn
  this is kind of level order traversal
*/
vector<int> zigZagTraversal(Node* root){
    vector<int> result;
    if( root == NULL){
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);

        // processing each level
        for( int i = 0; i< size; i++){
            Node* frontNode = q.front();
            q.pop();

            //normal insert or reverse insert
            int index = leftToRight? i : size - i - 1;
            ans[index] = frontnode-> data; // agar index de diya vector koo toh vector ka size initialise krna hoga

            if(frontNode -> left){
                q.push(frontNode-> left);
            }
            else if ( frontNode -> right){
                q.push(frontNode -> right);
            }

        }

        //direction change krni h after every level processing
        leftToRight = !leftToRight


        for( auto i : ans){
            result.push_back(i); // ans k sare elements in result 
        }
    }
    return result;

} // TC si O(n) SC is O( n ) too

/*
Boundary traversal
 sare boundary nodes ki value orint krni hai
    1. pehle left part print krenge
        except leaf node
    2. fir leaf node print krenge 
    3. now right part ko print krenge in reverse order and except the leaf node already printed
    using these three parts we ll solve the question

*/

void traverseLeft(Node* root, vector<int> &ans){
    if( (root == NULL) || ( root -> left == NULL && root -> right == NULL)){
       return;
    }
    ans.push_back(root -> data);
    if( root -> left){
        traversalLeft(root -> left, ans);
    }
    else{
        traversaLeft(root -> right, ans);
    }
}

void traverseLeaf(Node* root, vector<int> &ans){
    //base case
    if( root == NULL){
        return ;
    }
    if( root -> left == NULL && root -> right == NULL){
        ans.push_back(root -> data);
        return;
    }

    traverseLeaf( root -> left, ans);
    traverseLeaf( root -> right , ans)

}

void traverseRight( Node* root , vector<int> &ans){
    //base case
    if( (root == NULL) || ( root -> left == NULL && root -> right == NULL) ){
        return ;
    }

    if( root -> right ){
        traverseRight( root -> right, ans);
    }
    else {
        traverseRight( root -> left, ans);
    }

    //wapas agye 
    ans.push_back(root -> data);
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    
    ans.push_back(root -. data)
    
    //leftPart print krnaa hai
    traverseLeft(root -> left, ans);

    //traverse leaf nodes

    //for left
    traverseLeaf(root -> left, ans);

    //traverse right subtree
    traverseLeaf( root -> right , ans);

    // traverse right part 
    traverseRight( root -> right , ans);

    return ans;
}

/* // THIS IS THE HARD ONE
Vertical traversal of binary tree / vertical order traversal
 traverse along these vertical lines
 
 appoach :
  consider it like a number line 
  the center vertical line shall be at '0' and then at positive and negtive accordingly
  now we know horizontal distance of every node form root node
  whatever output we want is depended upon these numbers on the number line
  we can create a kind of mapping between the number line( horizontal distance) and levelwise nodes ke sath
  level wise nodes ka matlab h  ek or mapping level or uske nodes ka
  map<int, map<int, vector<int> > >
    horizontal distance  or level 
  
*/

vector<int> verticalOrder( Node* root){
       //hd     //lvl
    map<int , map<int, vector<int> > > nodes;
    queue< pair < node*, pair <int, int > > > q;
    vector<int> ans;

    if( root == NULL){
        return ans;
    }
    q.push( make_pair(root, make_pair(0,0)));

    while(!q.empty()) {
        pair<Node*, pair<int,int> > temp = q.front();
        q.pop(); // why this poping
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
            
        nodes[hd][lvl].push_back(frontNode->data); // this insertion was a bit confusing 
            
        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
                
        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
    }

    for(auto i: nodes) {
        for(auto j:i.second) {
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    
    return ans;
}

/*
Top view of binary tree
  
 approach
  firse number line
  pehle level zero ke liye jayenge
  fir aage
  har ek vertical line p pehla element hi lenge and all others tha is the bottom ones will be discarded
  horizontal distance k liye one to ine mapping honi chahiye
  similar t breadth first search
*/
vector<int> topView( Node* root){
    vector< int > ans;
    if( root == NULL){
        return ans;
    }

    map< int , int > topNode;
    queue < pair <Node* , int > > q; // int yha horizontal distance dikhayega

    q.push( make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //if one value is present for hd then do nothing
        if( topNode.find(hd) == topNode.end()){ // err...see this
            topNode[hd] = frontNode -> data;            
        }
        if( frontNode-> left){
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if( frontNode -> right){ // check for NULLity
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for( auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}
/*
Bottom View
 similar to previous but now from the bottom 

*/
vector<int> topView( Node* root){
    vector< int > ans;
    if( root == NULL){
        return ans;
    }

    map< int , int > topNode;
    queue < pair <Node* , int > > q; // int yha horizontal distance dikhayega

    q.push( make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        if( frontNode-> left){
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if( frontNode -> right){ // check for NULLity
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for( auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
} // bas ek condition hatayi hai all else is similar

/*
LEFT view of a binary tree
 har level ki first node ko print krna hai 

 level order or recursive do tareeke hain
 Bhut dekh liya BFS or LOT 
 ab recursion se krenge
*/
void solve(Node* root , vector<int> &ans, int level){
    //base case
    if( root == NULL){
        return;
    }
    if (level == ans.size()){ // we enterd into a new level
        ans.push_back(root -> data);
    }

    solve( root -> left, ans, level +1);
    solve( root -> right, ans, level +1);

} // make a recursive function call tabhi smjh aayega

vector<int> leftView(Node* root){
    vector < int > ans;
    solve( root , ans, 0);
    return ans;
}

/*
Right view of a binary tree
 har level ki first node ko print krna hai 

 level order or recursive do tareeke hain
 Bhut dekh liya BFS or LOT 
 ab recursion se krenge
*/
void solve(Node* root , vector<int> &ans, int level){
    //base case
    if( root == NULL){
        return;
    }
    if (level == ans.size()){ // we enterd into a new level
        ans.push_back(root -> data);
    }

    solve( root -> right, ans, level +1); // iska order change kiya gya h bas
    solve( root -> left, ans, level +1);

} // make a recursive function call tabhi smjh aayega

vector<int> leftView(Node* root){
    vector < int > ans;
    solve( root , ans, 0);
    return ans;
} // bas hogya 

// hw : diagnol traversal of binary tree
// see all complexities of all these traversals