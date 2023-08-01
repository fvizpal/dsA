/*
Minimum Number of Coins
 to make an amount
 you have an input array which has denominations of coins
 and the amount that you need to make

 whaat would be the minimum number of coins to make up that amount
 
 pehle recursion kenge
 fir memo add krnge
 fir tabulate
 fir SC optimise

*/

int solveRec(vector<int> &num, int x){
    //base case
    if( x == 0){
        return 0;
    }
    if( x < 0){
        return INT_MAX;
    }

    int mini = INT_MAX;
    for( int i : num){
        int ans = solveRec( num, x - i);
        if( ans != INT_MAX){
            mini = min( mini , 1 + ans);
        }
    }

    return mini;
} // TC is exponential here

int minimumCoins(vector<int> &num, int x){

    int ans = solveRec( num , x);
    if( ans == INT_MAX)     return -1;

    return ans;

}

// ye TLE dega // lets add memo

int solveMem( vector<int> num, int x, vector<int> dp){
    //base case
    if( x == 0)     return 0;

    if( x < 0)      return INT_MAX;

    if( dp[x] != -1)    return dp[x]; // agr already available ans hai toh vahi return karde

    int mini = INT_MAX;
    for( int i = 0; i< num.size(); i++){
        int ans = solveRec(num, x - num[i]);
        if( ans != INT_MAX){
            mini = min( mini, 1+ans);
        }
    }

    dp[x] = mini;

    return mini;

} // TC O(x)
int minimumCoins( vector<int> &num, int x){
    vector<int> dp(x+1, -1);
    int ans = solveMem(num, x, dp);

    if( ans = INT_MAX)      return -1;
    else        return ans;
}



// SOLVING USING TABULATION
int solveTab( vector<int> num, int x){

    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for( int i = 1; i <= x; i++){
        // solving for every amount figure from 1 to x
        for( int j = 0; i < num.size(); j++){
            if( i - num[j] >=0 && dp[i - num[j]] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i-num[j]]);
            }
        }

    }

    if( dp[x] == INT_MAX)   return -1;

    return dp[x];

} // TC and SC is O (x)

int minimumCoins( vector<int> &num, int x){
    return solveTab(num, x);
}


// yha bhi kya space optimise kar skte hn
// yha nhi ho payega !???
