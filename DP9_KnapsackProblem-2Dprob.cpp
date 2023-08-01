/*
Knapsack problem 0/1
 a thief havong knapsack can carry w weight
 there are total n items and every item has some weight
 and every item has some value

 the theif has to rob such that it can have maximum value in his knapsack
 weight w se jyada nhi hona chiye

 brute force kehta hai ki sare combination nikalo for the items within w weight range 
 then find there values 
 then return whichever combination has maximum 
 
*/

int solve( vector<int> &weight, vector<int> &value, int index, int capacity ){
    //bas case
    // fi only one item to steal , then just compare its weight with the knapsack capacity
    if( index = 0){
        // jab mai last element pe aaunga 
        if( weight[0] <= capacity){
            return value[0];
        } 
        else {
            return 0;
        }
    }

    //jis item p khade hai 
    int include = 0;
    if( weight[index] <= capacity){
        include = value[index] + solve( weight, value, index-1, capacity - weight[index])
    }
    //exclusion
    int exclude = 0 + solve(weight, value, index-1, capacity);

    int ans = max(include, exclude);
    return ans;
}

int knapsack(vector<int> &weight, vector<int> value, int maxWeight){

    return solve(weight, value, n-1, maxWeight);
}
// but ye TLE dega since TC is exponential

// lets then add memoization

int solveMem( vector<int> &weight, vector<int> &value, int index, int capacity ,vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1))){
    //bas case
    // if only one item to steal , then just compare its weight with the knapsack capacity
    if( index = 0){
        // jab mai last element pe aaunga 
        if( weight[0] <= capacity){
            return value[0];
        } 
        else {
            return 0;
        }
    }

    if( dp[index][capacity] != -1){
        return dp[index][capacity];
    }

    //jis item p khade hai 
    int include = 0;
    if( weight[index] <= capacity){
        include = value[index] + solveMem( weight, value, index-1, capacity - weight[index], dp);
    }
    //exclusion
    int exclude = 0 + solveMem(weight, value, index-1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return ans;
}

int knapsack(vector<int> &weight, vector<int> value, int maxWeight){
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    //is recursive call me so state{ index, capacity} ki valur change horhi hai toh 2D dp

    return solveMem(weight, value, n-1, maxWeight, dp);
}

// lets now see bottom up approach - using tabulation

// int solveTab()
int solveTab( vector<int> &weight, vector<int> &value, int n, int capacity ){
    
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

    // 2. analyse the base case
    for( int w = weight[0], w<=capacity, w++){
        if( weight[0] <= capacity){
            dp[0][w] = value[0];
        }
        else{
            dp[0][w] = 0;
        }
    }

    for( int index = 1; index < n; index++){
        for( int w = 0; w<= capacity; w++){
            int include = 0;

            if( weight[index] <= w){
                include = value[index] +dp[index-1][w-weight[index]];
            }

            int exclude = 0 + dp[index-1][w]; // we get 0 value on excluding

            dp[index][w] = max(exclude, include);
        }
    }

    return dp[n-1][capacity]
}


//space optimising the same
int solveSO( vector<int> &weight, vector<int> &value, int n, int capacity ){
    
    // vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    // 2. analyse the base case
    for( int w = weight[0], w<=capacity, w++){
        if( weight[0] <= capacity){
            curr[w] = value[0];
        }
        else{
            prev[w] = 0;
        }
    }

    for( int index = 1; index < n; index++){
        for( int w = capacity; w >= 0; w--){ 
            int include = 0;

            if( weight[index] <= w){     //orev
                include = value[index] + curr[w-weight[index]];
            }

            int exclude = 0 + prev[w];

            curr[w] = max(exclude, include);
        }
        // prev = curr
    }

    return curr[capacity] // return perv[capacity]
}

// ham chahe toh prev array ki bhi jaroorat bhi nhi hai
// nut left to right chalne pe it will give wrong answer as it depends on previous solutions as well
// right to left chal jayega