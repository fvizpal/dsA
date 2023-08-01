/* 1. Kth largest sum subarray
 given an array we want to output kth largest subarray sum
 
 approach
    brute:
     . do loop chala ke sare subarrays ka sum save lar liya in say a vector
     . then sort this vector and find kth largest
     . TC O(n^2*logn) hojayegi
    using min heap - as before to find largest element
     . 
*/
int getKthLargestSumSubarray( vector<int> &arr, int k){
    vector<int> sumStore;
    int n = arr.size();

    for( int i = 0; i < n; i++){
        int sum = 0;
        for( int j = i; j < n; j++){
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }
    sort( sumStore.begin(), sumStore.end());

    return sumStore[sumStore.size() - k];
}

//OPTIMISED APPROACH
int getKthLargestSumSubarray( vector<int> &arr, int k){
    priority_queue<int , vector<int>, greater<int>> mini;

    int n = arr.size();
    for( int i = 0; i < n; i++){
        int sum = 0;
        for( int j = i; j < n; j++){
            sum += arr[j];
            if( mini.size() < k){
                mini.push(sum);
            }
            else{
                if( sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }

    return mini.top(); 
}
// SC optimise hogyi h yha // TC no

/* 2. Merge k sorted arrays
 given k sorted arrays . merge them all
 
 approach
    . create ans vector
    . traverse them all and fill it into 
    . then sort the ans array
    . TC  O(n*k log(n*k))
    # isme ye fact ki elements sorted hai use nhi kiya . not optimised

    say we have k elements ( the first ones of the arrays)
    how to find minimum among these 
    - yeah! using min heap
    so find mini element and put this in an array and then its next 
    keep on doing till minheap.size > 1
    but we ll need our own DS depending on input type

*/
class node{
    public:
    int data;
    int i;
    int j;
    //constructor
    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class comp{ // a comparator rather than greater is needed this time 
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
}

vector<int> mergeSortedArrays( vector<vector<int>> &kArrays, int k){
    priority_queue<node*, vector<node*>, comp> minHeap;

    //step1: saare arrays k first element insert karne hai
    for( int i = 0; i < k; i++){
        node* temp = new node( kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    //step2: min
    while( minHeap.size() > 0){
        node* temp = minHeap.top();
        ans.push_back(minHeap.top());
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if( j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }

    return ans;
} 
// TC O(n*k logk) // SC O(K)

/* 3. Merge k sorted linked lists
 do not use extra memory

 approach
    ek vector bana lo or saare LL ke values copy kardo
    fir isko sort kardo
    ab saare LL ko join kardo
    now copy all elemnts in vector in this joined LL
    return heads
    TC O(n*k log(n*k))

    OPTIMISED :
     create minHeap . sabka first ka data utha lenge LL ka
     jabtak mera minHeap empty nhi hota  head tail ko minheap ke top pe le jayenge
     

*/

class compare{
    public:
    bool operator(ListNode* a, ListNode* b){
        return a->data > b->data;
    }
}

ListNode* mergeKSortedLinkedLists( vector<ListNode*> &listArray){
    priority_queue<ListNode* , vector<ListNode*> , compare> minHeap;

    int k = listArrays.size();
    if( k == 0) return NULL;

    //step1:
    for( int i =0; i < k; i++){
        if( listArray[i] != NULL){
            minheap.push(listArray[i]);
        }
    }

    ListNode* head = NULL;
    ListNode* tail = NULL;

    while( !minHeap.empty()){
        ListNode* top = minHeap.top();
        minHeap.pop();

        if( top -> next != NULL){
            minHeap.push(top->next);
        }

        if( head == NULL){
            head = top;
            tail = top;

        }
        else{ // insert at end
            tail->next = top;
            tail = top;
        }
    }

    return head;
} // TC O(k logk) + O(n*k logk) ; n is no. of nodes in LL
// SC O(k)

HW ek aur approach dekhen