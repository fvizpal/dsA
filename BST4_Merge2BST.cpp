/*
Merge two BSTs
 given two BSTs merge them to make one a BST

 approach 1:
  ham dono BST ka inorder nikalenge 
  wo do sorted array honge now we will merge thess two arrays
  to get one array which shall be inorder for our merged BST;
  Now make a BST from this as we saw earlier
  TC ans SC both would be O( m + n );


*/
void inorder(Node* root, vector<int> &in){
    if( root == NULL)   return ;

    inorder( root -. left);
    in.push_back(root -> data);
    inorder( root -> data);
}

vector<int> mergeArray( vector<int> a, vector<int> b){
    vector<int> ans( a.size() + b.size());
    
    int i = 0, j = 0;
    int k = 0;
    while( i < a.size() && j < b.size()){
        if( a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j];
            j++;
        }
    }

    while( i < a.size()){
        ans[k++] = a[i];
        i++;
    }
    while( j < b.size()){
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

Node* inorderToBST( int s, int e, vector<int> &in){
    //base case
    if( s>e)    return NULL;

    int mid = ( s + e ) / 2;

    Node* root = new Node(in[mid]);
    root-> left = inorderToBST(s, mid - 1, in);
    root-> left = inorderToBST(mid + 1, e, in);

    return root;
}

Node* mergeBST( Node* root1, Node* root2){

    //step 1 : store inorder
    vecotr<int> bst1, bst2;

    inorder( root1, bst1);
    inorder( root2, bst2);

    // step 2: merge both sorted arrays
    vector<int> mergeArray = mergeArray(bst1, bst2);

    // use mreged array to make a BST
    int s = 0, e = mergeArray.size - 1;
    return inorderToBST(s, e, mergeArray);

} // TC ans SC is O( m+n )
// follow up: SC should be O( h1 + h2);
// approach 2:
//  step 1: root1 converted to a Sorted LL; ans root 2 as well

//  step 2: merge these two sorted LL; tc WLD BE o(M+N)
//             and since only pointers are being modified so no use of extra Space

//  step 3: make a BST from the sorted inorder LL

// converting BST into sorted DLL
// using recursion complete one part with recursion ; it will return a head
// now point this in roots left or right whichever you did convert to LL node
// now recurse through 
// if tree is a BST the LL thus obtained would be sorted
// ? why we processed right first and not left
//  see prev : flatten a BT into LL

void convertIntoSortedDLL(Node* root, ListNode* &head){
    //base case
    if( root == NULL)   return NULL;

    convertIntoSortedDLL( root -> right, head);

    root -> right = head;

    if( head != NULL)   head -> left = root;

    head = root;

    convertIntoSortedDLL(root -> left, head );
}

// merging two DLL into one sorted DLL
ListNode* mergeLL( ListNode* head1, ListNode* head2){
    
    ListNode* head = NULL;
    ListNode* tail = NULL;

    while( head1 && head2){
        if( head1->data < head2->data ){
            if( head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if( head == NULL){
                head = head2;
                tail = head2;
                head1 = head2->right;
            }
            else {
                tail->right = head2;
                head2->left = tail;
                tail = head1;
                head2 = head1->right;
            }
        }
    }

    while( head1){
        tail-> right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while( head2 ){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

//now sorted LL se BST bnana hai
// starting n/2 nodes se left tree bnaya 
// next node would be root node
// issi root ke left m lga do
// head ko aage bdhao
// aur right sub tree bna lo ( n - n/2 -1 nodes to right of root node)
// 
// count nodes
int countNodes( Node* head){
    int cnt = 0;
    Node* temp = head;
    while( temp ){
        cnt++;
        temp = temp -> right;
    }
    return cnt;
}

//
Node* sortedLLtoBST(Node* &head, int n){
    if( n <= 0 || head == NULL)     return NULL
    
    Node* left = sortedLLToBST( head, n/2);

    Node* root = head;
    root->left;

    head = head -> next;

    root -> right = sortedLLToBST( head, n - n/2 -1);
    return root;
}

Node* mergeBST( Node* root1, Node* root2){

    Node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;
    
    Node* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;
    
    //merging LL
    Node* head = mergeLL( head1, head2);

    //convert SLL to BST
    int count = countNodes(head);
    return sortedLLToBST(head, count);


}

