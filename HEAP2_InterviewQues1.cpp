/* 1. Kth smallest element
 input : array 
 find kth smallest element in the array

    approach
     1. sort and return 3rd element     
     2. heap - first k element k liye max heap banayenge
                for rest element if( elem < rootofMaxHeap) then heap.pop() and heap.push(elem)
                ye sab karne pe k elements bachenge aur ye smallest honge ... toh heap ka top hi vo element hoga 
*/
int KthSmallestElement(vector<int> &arr, int k){

    priority_queue<int> pq;
    for( int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    // 2.
    for( int i = k; i < arr.size(); i++){
        if( arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    // 3.
    return pq.top();
} // largest element ke liye min heap bana lena
// SC O(k) // TC O(n*log n)


/* 2.  isBinaryTreeHeap
 given a binary tree in input;
 return if it is a heap or not ; max wala
 
 approach
    1. check if CBT
        1. nodecount hona chahiye
        2. now left node shld be at 2*i+1 and right at 2*i+2 for each in array; 
            if left or right position comes greater than nodecount => not a CBT
        3. return bool
    2. check if maxheap
        1. ispe aaye iska matlab CBT toh hai; three types of nodes in a tree
        2. if leaf node return true
        3. if right == null, return root.data > root.left.data;
        4. if both child exist, return child ke data shld be less than parent node
        5. left aur right me recursivec call maar do
*/
int countNode(Node* root){

    if( root == NULL){
        return 0;
    }

    int ans = 1+ countNode(root->left) + countNode(root->right);

    return ans;
}
bool isCBT( Node* root, int index, int cnt){
    if( root == NULL){
        return true;
    }
    if( index >= cnt){
        return false;
    }
    else{
        bool left = isCBT(root->left, 2*index +1, cnt);
        bool right = isCBT(root->right, 2*index+2, cnt); 
        return left&&right;
    }
}
bool isMaxOrder( Node8 root){
    //leaf node
    if( root -> left == NULL && root -> right){
        return true;
    }
    if( root->right == NULL){
        return (root->data > root->left->data);
    }
    else {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder( root->right);

        return ( left && right && (root->data > root->left->data) && (root->data > right->right->data));
    }
}
bool isHeap( Node* root){
    int index = 0;
    int totalCount = countNode(root);
    if( isCBT(root, index, totalCount) && isMaxOrder(root)){
        return true;
    }

    return false;
} // TC O(n)+O(n)+O(n)  //SC O(h)


/* 3. Merge two Binary max heap
 remembre merge two BSTs kuch kuch vesa hi
 Given two heaps merge them to form one - input is in vector form

 merge these two arrays
 now heapify using the heapify function

 TC O(n)

*/

// remember to use zero based indexing logic
void heapify(vector<int> arr, )

vector<int> mergeHeaps( vector<int> &a, vector<int> &b){
    // 1. merge the arrays
    vector<int> ans;
    for( auto i : a){
        ans.push_back(i);
    }
    // stl for inserting vector b
    ans.insert( ans.begin()+a.size(), b.begin(), b.end());

    // 2.  build heap
    int n = ans.size();
    for( int i = n/2-1; i >=0; i--){
        heapify(ans, n, i);
    }

    return ans;
} //  TC O(n);


/* 4. Minimum cost of ropes
 N ropes with different lengths, we need to connect these ropes into one rope. 
 The cost to connect two ropes is the sum of their lengths
 Task is to connect the ropes with minimum cost
 
 do  minimum uthao sum; sum karo ; unki jagah yhi sum daal do;
 again repeat
 
 min heap banana lena for minimum elements
*/

long long minCost(long long arr[], long long n){
    // create a min heap
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    for( int i = 0; i < n; i++){
        pq.push(arr[i]);
    }

    long long cost = 0;

    while( pq.size() > 1){
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum  = a+b;
        cost += sum;
        pq.push(sum);
    }
} // SC O(N)    TC is O(n*logn)

/* 5. Convert BST to Min Heap
 given a BST( is also a CBT ) convert it to a min heap
 
 approach:
    1. if it is already a CBT then its structure won't change
    2. so only node values will change
    3. inorder traversal se sorted order me values mil jayengi
    4. preorder se  NLR milega aur issi order me ham apni heap tree( ussi BST tree me ) me fill karte jayenge

*/ // HW :]


