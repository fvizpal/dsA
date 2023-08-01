/*
Heaps - Minheap and maxheap
    we will implement heaps in form of arrays 
    where top node( root node) is at the 1 th index of that array and there childrens(all childrens at level)
    follow from left to right.
    So  left child of a node which is at i th position will be at 2*i position; and right child at 2*i+1 position
    parent of any node shall be found at i/2 th position
    
    *in a Complete Binary Tree the leaf node lies from n/2+1 to n th index

*/



#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    //construcor
    heap(){
        arr[0] = -1; // no fayda
        size = 0;   // initialisation
    }

    //insertion in max-Heap  // TC is O(log n)
    void insert(int val){

        size++;
        int index = size;
        arr[index] = val; // pehle toh akhir me daaldo 

        while(index > 1){ // fir uski correct position pe le jaoo
            int parent = index / 2;

            if( arr[parent] < arr[index] ){ // if parent not greater than swap keep doing so until the condition applocalble
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){ // zero pe kuch nhi dala hai
        for ( int i = 1; i <= size;i++){
            cout << arr[i] << " ";
        } cout << endl;
    }
    
    /* DELETION - for MAX HEAP
        jab deletion ki baat kar rhe hai toh hamesa root node ko delete krne ki baat kar rhe hain
        step1:
        last me jo bhi node hai uuse root node pe daaldo  swap kardo(last and root node) or simply pu by a[1] = a[n]
        step 2:
        remove last node
        step 3:
        propogate root node to correct position
    */
    //deletion in Max haep             // TC O(log n )
    void deleteFromHeap(){
        if(size == 0){
            cout << "Nothing to delete"<< endl;
            return;
        } 

        arr[1] = arr[size]; // putting last into root node
        size--; // remove last element

        //take root node to its correct position
        int i = 1;
        while( i < size){
            int leftIndex = 2* i;
            int rightIndex = 2*i + 1;

            //comparing with childrens
            if(leftindex < size && arr[i] < arr[leftIndex] ){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex
            }
            else if( rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else{ // jab sab shi hai kuch krne ki need nhi so return
                return;
            }
        }
    }
};

/*HEAPIFY into max heap      // TC is O( log n )
    n/2 se n th index tak process karne  ki need hi nahi hai since they are all leaf nodes
    // ot build heap TC is O(N) //HW
*/ // int i wale node ko sahi position tak leke jayenge
void heapify( int arr[], int n , int i){
    int largest = i;
    int left = 2* i;
    int right = 2*i + 1;

    if( left <= n && arr[largest] < arr[left]){ // zero based indexing me '<' ye chalta hai; yha '<=' karna hoga
        largest = left;
    }

    if( right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if( largest != i){
        swap( arr[largest],arr[i]);
        heapify(arr,n, largest);
    }
}

/* HEAP SORT
    heap bana pda hai sorted order me elemets dene hai; max heap ko non decreasing order me sort karenge
    Algo:
    1. swap root element with last element , size-- kardo matlab last node hata diya hai
    2. root node ko correct position pe le aao
    3. again swap last with last node ; size-- again
    4. again shi jagah pe le jao
    5. repeat same until we reach last element
*/
void heapSort(int arr[], int n){
    int t = n;

    while( t > 1){
        //step 1: swap
        swap(arr[t], arr[1]);
        //step1.a
        size--;
        //step 2
        heapify(arr, size, 1); // 1 is here index of first node // need to process till leftover sixe only
    }
}

// priority queue STL se ye sab implement kar skte hain
#include<queue>

priority_queue<int> pq; // this in itself is a MAX HEAP
pq.top(); // shall be the maximum element
pq.pop(); // will pop this max element
pq.empty(); // return boolean 
pq.size(); // returns size

//for  min heap
priority_queue<int, vector<int>, greater<int>> minHeap;
// now this minHeap will be our MIN HEAP
// swap se kya hota hai

int main(){
    heap h;

    h.insert(10);
    h.insert(  );


    return 0;
}