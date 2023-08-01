/* 1. smallest range in k sorted list
 given k list in input in output smallest range in which theres at least on element of each list
 
 approach
    brute force :
     . saari list me ranges nikal lo and check if unn me se range me smallest and jisme saare aate ho

    another
     . ek list banao lisNode pointer ka aur sabke pehle nodes rakhlo
     . now min aur max values inme se nikal lo sabke first nodes se hi kuyki list asccending order me sorted hai
     . now max ko toh increase kar nhi skte toh min ko increase krenge aur check krenge ki smallest range hai ki nahi
     . agar smallest hai toh update the answer 
     . TC n*k*k^2 O( n*k^2) // sc is O(k)

    appraoch 3 - using heaps
     . heap banao k size ka ( min wala ) . usme har list ka starting element dalna hai
     . rukna hai tab koi bhi ek list exhaust ho jaye
     . while list is not empty tbtk top element nikalo or usse pop karo this will be the 
     . minimum element 
     . ab jo range(max - min) arhi hai kya vo pehle ke answer se chotta hai toh update kardo
     . fir usme jo top pe tha uske next wala element update karna hoga 
     . agar min ka col size se chota hai toh next element exist karta hai
     . maxi ko update kardo with max( maxi, arr[same row][next col]) se
*/
class node{
    public:
    int data;
    int row;
    int col;

    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};
class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
}

int kSorted( vector<vector<int>> &a, int k, int n){
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node*, vector<node*> , compare> minHeap;
    // 1. create a minheap for starting element of each list and tracking mini/ maxi
    for( int i = 0; i < k; i++){
        int element  = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini;
    int end = maxi;
    
    // processing ranges
    while( !minHeap.empty()){
        node* temp = minHeap.top()
        miniHeap.pop();

        mini = temp -> data;

        // range update
        if( maxi - mini < end - start){
            start = mini;
            end = maxi;
        }
        //existnace of next element
        if(temp->col + 1 < n){
            maxi = max(maxi, a[temp->row][tmep->col + 1]);
            minHeap.push(new node(a[temp->row][tmep->col + 1], temp->row, temp->col + 1));
        }
        else{ // if does not exist
            break;
        }
    }

    return (end - start + 1);
}

/* 2. Median in a data stream
 Given a stream of integer
 find median at each point of flow of data stream
 stream sorted order me aa rhi hai

 approach
    brute:
     . runnig stream hai toh aise sorting algo lagaye jisme new data aane pe bhi aa jaye
     . insertion sort is viable, has TC O(n^2)
     . par jada hogyi TC ;
    
    optimised:
     . even ya odd sized ho skta hai accordingly median bich ka element hoga ya do bich ke ka average hoga
     . teen options yha ho skte hain
     . agar odd size ka array hai 
       . median k left part wale sare elements median se chhote honge
       . aur right me bade; 
     . odd size wale me left aur right ke size alag honge
     . even size me left and right both same size ke honge

     signum function ka utilisation bhi karenge
      . agr a == b toh returns 0;
      . agr a > b toh returns 1;
      . agr a < b toh returns -1;

     algo :
     . for loop from i = 0 to n
     . element = arr[i];
     . ans = call_median(element, ____ ) // ek function banayenge call_median ka uspe median aur kuch pas krenge lets see what this 'aur kuch' will be
     . now as we discussed about the left and right part to the median with lower and greater values respectively
     . left part ko maxHeap lele and right part ko minHeap
     . incase of even sized array both these heaps will have same size
      . in dono heaps ke top elements ka average hi hamara median hojayega
     . agr odd sized array hai toh left age n size ka hai toh right n-1 size ka hoga
      . median simply maxHeap ka top ho jyaga
      . agr left n-1 size ka hai or right n size ka 
      . toh median minHeap ka top hojayega
     bas fir ans return kar do 

    callMedian(element, maxheap, minheap, &median){
        switch( signum (maxHeap.size, minheap.size))
            case 0: // both of same size // that is even size wala array
            if( element > Median) minheap.push(element);
            median = minHeap.top();
            median ....

            case 1:
                if( element > Median)
                    minheap.push( element );
                    median = avg(maxHeap(), minHeap.size())
                else
                    minHeap.push(maxHeap.top());
                    maxheap.pop();
                    maxheap.push(element);
            case -1:
                if( element > median)
                    // toh miHeap ke top ko pehle maxHeap me daal denge fir iss nye element ko daalenge nhi toh size me gadbad hogi
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push( element)
                    median = avg( mintop, maxtop)
                else
                    maxheap.push(element)
        }
    }
*/

int signnum(int a, int b){
    if( a== b) return 0;

    else if( a > b) return 1;

    else return -1;
}
void callMedian( int element, priority_queue<int> &maxi, 
                    priority_queue<int, vector<int>, greater<int>> &mini, int &median)
{
    switch( signum(maxi.size(), mini.size())){

        case 0: 
            if( element > median){
                mini.push(element);
                median = mini.top();
            }
            else{
                maxi.push(element);
                median = maxi.top()
            }
            break;
        
        case 1:
            if( element > median){
                mini.push_back(element);
                median = (mini.top() + maxi.top()) / 2;
            }
            else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
                median = (mini.top() + maxi.top()) / 2;
            }
            break;

        case -1:
            if( element > median){
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
                median = (mini.top() + maxi.top()) / 2;
            }
            else{
                maxi.push(element);
                median = (mini.top() + maxi.top()) / 2;
            }
            break;
    }
}
vector<int> findMedian( vector<int> &arr, int n){
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;

    for( int i = 0; i < n; i++){
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }

    return ans;
}