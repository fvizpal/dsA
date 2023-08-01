/* 1
Queue Reversal
 just reverse the queue

 approach{
    1. stack ka use kar len
    stack m daal ke nikalenge toh reverse m niklega

    2. recursion se bhi toh ho skta hai
    pehle ko side m rkhlo , or baki ko recursion ke havale kar do reverse krne 

 }
*/
queue<int> rev( queue<int> q){
    stack<int> s;

    while( !q.empty()){
        int elem = q.front();
        q.pop()
        s.push(elem);
    }

    while(!s.empty()){
        int elem = s.top();
        s.pop();
        q.push(elem);
    }

    return q;
} 
// TC is O(N)
// SC is O(N)

// Recursion WALA TAREEKA
khud karo 


/* 2 
Find first negative integer in every window of size K;
 given an array 
 in window size of say k return first negative number if no negative 
 return 0;

 appraoch{
    doubly ended queue that is ek 'deque' ka use krenge
    first k element daalenge 
    i.e. pehli window aagyi 
    Now processing aage wali windows 
    agli window k liye ek nya number add hota hai ek remove hota hai
    
 }
*/

vector<long long> printNegativeInteger( long long int A[], long long int N, long long int k){
    deque<long long > dq;
    vector<long long> ans;

    //process first window of size k;

    for( int i = 0; i < k; i++){
        if( A[i] < 0){
            dq.push_back(i);
        }
    }

    //store answer fo first k sized window
    if( dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    //process for remaining windows
    for( int i = 0; i < N; i++){

        //removal;
        if( !dq.empty() && i-dq.front() >= K){
            dq.pop_front();
        }

        //addition
        if( A[i] < 0){
            dq.push_back(i);
        }

        //ans store 
        if( dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }

    return ans;
}
// BUT NO YE OPTIMAL APPRAOCH NHI HAI
// wo apke liye HW hai


/* 3
REVERSE FIRST K ELEMENT OF A QUEUE
 
 approach{
    stack ka use kar skte hn 
    fetch first k element from queue and put into stack
    Now get them out of stack

 }
*/

queue<int> modifyQueue( queue<int> q, int k){
    //step 1 : pop first k elment from queue into stack
    stack<int> s;

    for( int i = 0; i < k; i++){
        int val = q.front();
        q.pop();
        s.push(val);

    }

    //step2: fetch form stack and put into queue 
    while( !s.empty()){
        int val = s.top();
        s.pop()
        q.push(val);
    }

    //step3: fetch forst n-k element formQ and pushBack

    int t = q.size() - k;
    while( t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}
//TC would be O(n)
// SC is O(k) of stack

/* 4
First non repeating character in a stream
 repeating ki jagah # print krna hai

 approach{
    hame ek cnt store krna hoga kitni baar ek charcter aya hai
    map use krenge count k liye // taki pta lge ki repeating hai ya nhi
    ek aur DS chiye ( queue) jisme sare char dalenge
    aur iske front() ko check krnege if that charcter in repeating or not

 }
*/

string FirstNonRepeating( string s){
    unoredered_map <char, int> cnt;
    queue<int> q;
    string ans = "";
    
    for( int i = 0; i < s.length(); i++){
        char ch = s[i];

        //increase cnt;
        cnt[ch]++;
        
        //queue me push karo
        q.push(ch);

        while( !q.empty() ){
            if( cnt[q.front()] > 1){
                // repeating char hai
                q.pop();
            }
            else{
                //non repeating mil gya 
                ans.push_back(q.front());
                break;
            }
        }

        if( q.empty()){
            ans,push_back('#');
        }
    }
    return ans;
} // TC


/* 5
Circular Tour
 there is a circle and N petrol pump hai
 we know how much petrol each pumo has
 distance of next petrol pump bhi pta hai 
 we need to find such starting point that if a truck start from ; wld complete the whole circle
 1 unit of petrol se 1 unit of distance cover kar skte hn

    lets say ( petrol(P), dist(D)) me data de rkha hai 
    agar P-D > 0 tabhi aap next petrol pump tak pahuch skte hn 
    toh either it wld be '< 0' or '>= 0'
    agar greater hoga toh wo next petrol pump ke petrol m add ho jayega;  mtlb truck jada cover kar skega

 approach{
    1. brute force approach will say try starting from every possibility if it is feasible O(n^2) will be TC
    
    2. queue based approach : front aur rear lets say starting element pe lage hn
       if travel possible rear++ kar dena
       aisa krte krte if front == rear ho jaye toh tumne circle complete kar liya 
       else ( that is agar nhi h posible ) toh front = rear+1 pe le ayenge ! front++ kyu nhi ?!?
            aur front aur rear ko front ki place p le ayenge or hmara possible start bhi ab ye hi ho jayega
        worst case me isme hame 2 bar visit kerna pad skta hai
        ham ye nhi chahte 

    3. ham deficit ko bhi store krenge
       

 }

*/
struct pump {
    int petrol;
    int distance;
};

int circularTour( pump p[], int n ){
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for( int i = 0; i < n ; i++){
        balance += p[i].petrol - p[i].distance;
        if( balance < 0){
            deficit += balance;
            start = i+1; // ye wo front = rear + 1 hai
            balance = 0;
        }
    }
    if( deficit + balance >= 0)
        return start;
    else 
        return -1;
}

/* 6
Interleave fisrt half of the queue with the second half
 

 appraoch{
    fetch first half element of the queue and put into new queue
    jab tak new queue empty nhi hoti tab tak ek k bad ek dono k front element lagate jao
 
    // lekin stack ka use krna hai  //  HW me ye toh kiya hi tha ki implement queue using stack and vice versa
    // iski TC and SC kya hogi
 }

*/

queue<int> interleaveQueue(queue<int> q){


}


/* 7
K queues in an array
 single array ka use krke k queues implement krna hai
 // similar to N stacks in an array

 array ko K parts me break krenge or queues bnayrnge


*/
class kQueue{
    public:
        int n ;
        int k;
        int*front;
        int *rear;
        int *arr;
        int freeSpot;
        int *next;

    public:
        kQueue{
            this->n = n;
            this->k = k;
            front = new int[k];
            rear = new int[k];
            for( int i= 0; i < k; i++){
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for( int i=0; i<n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freeSpot = 0;
        }

        void enqueue(int data, int qn){
            //overflow
            if( freeSpot == -1){
                cout << "No empty space is present" << endl;
            }

            //find first free index
            int index = freeSpot;

            // update freeSpot;
            freeSpot = next[index];

            //check whether first element
            if( front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                //link new element to the previous element
                next[rear[qn-1]] = index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn-1] = index;

            //push element
            arr[index] = data;
        }

        void dequeue(int qn){
            //underflow
            if( front[qn-1] == -1){
                cout << "Queue Underflow"<<endl;
                return -1;
            }

            //find index to pop
            int index = front[qn-1];

            //front ko aage badhao
            front[qn-1] = next[index];

            //freeslots ko manage karo
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }
};
int main() {

    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

    return 0;
}

/* 8 
sum of minimum and maximum element of all subarrays of size k
  given an array and window size K
  in every window max and min element ka sum return krna hai

  approach{
    loop jo har sigle element ko traverse krega 
    max and min nikalke har window m ; sum kar lenge 
    TC O(n^2) ho jayegi

    Dequeue ka use kernge similar to forst negative element in window size K Question ki trha
    par yha do aisi deque use krenge maxi and mini
    maxi me decreasing oreder me element honge 
    aur mini me increasing order me 

  }
*/

int func( vector<int> arr, int n , int k ){
    deque<int> maxi(k);
    deque<int> mini(k);

    //addition of first k size window
    for( int i = 0; i < k; i++){
        while( !maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while( !mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    for( int i = k; i< n; i++){
        ans += arr[maxi.front()] + arr[mini.front()];

        //next window

        //removal
        while(!maxi.enoty() && i - maxi.front() >= k){
            maxi.pop_front();
        }
        while(!mini.emopty() && i - mini.front() >= k){
            mini.pop_front();
        }

        //addition
        while( !maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while( !mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);

    }
    
    // comsider last window
    ans += arr[maxi.front()] + arr[mini.front()];

    return ans;
}
// TC is O(n)
// and SC is HW



