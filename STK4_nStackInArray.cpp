/*
Implement n stacks in an array
 kisi bhi stack me push or pop kar saku
 
 see notebook for the approaches

 variables pre used
 n: no. of stacks
 s: size of array
 q: no. od queries
 
 queries are what all we want to do // stack commands 
 // pop(2); // pop from second stack
 // push( 10, 1); // push 10 in first stack

    algo: to push: 
    1. find index
        int index = freeSpot
    2. update freeSpot
        freeSpot = next[index];
    3. insert in array
        arr[index] = x;
    4. update next to // purana wala top
        next[index] = top[m-1]
    5. update top 
        top[m-1] = index
*/

class nStacks{
    int *arr;
    int *top;
    int *next;

    int n, s;

    int freespot;

    public:
    //intitalise the DS
    nStacks(int N, int S){
        n = N;
        s = S;
        arr= new int[s];
        top = new int[n];
        next = new int[s];

        //top initialise
        for( int i = 0; i < n; i++){
            top[i] = -1;
        }

        //next initialise
        for( int i = 0; i < s; i++){
            next[i] = i+1;
        }
        //update lasr index value to -1
        next[s-1] = -1;

        //initialise freespot
        freespot = 0;

    }

    // pushes 'x' into Mth stack . returns true if pushed successfully else false
    bool push( int x, int m){

        //check for overflow
        if( freespot) == -1{
            return false;
        }

        //find index
        int index = freeSpot;

        //insert element into array
        arr[index] = x;

        //update freespot
        freespot = next[index];

        //update next
        next[index] = top[m-1];

        //update top
        top[m-1] = index;

        return true;

    }

    //pops element from Mth stack . return -1 if stack is empty
    int pop( int m){
        //check underflow condition
        if( top[m-1] == -1){
            return -1;
        }

        // go ulta to pushing

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};
// TC wld be O(1) // for both push and pop
// SC is O(S+N)

