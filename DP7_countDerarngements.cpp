/*
Count Derangements
 it is a permutation of n elemnts , such that no element 
 appears at its original position

 we need to find total no. of derangements possible for a set of n elements

*/
#define MOD 1000000007
long long int countDerangements( int n ){
    //base case
    if( n == 1){
        return 0 ;

    }
    if( n == 2)         return 1;

    int ans = (n-1)*(countDerangements(n-1) + countDerangements(n-2));
    // par mod krke likhna hai
    /int ans = ((n-1)%MOD)*((countDerangements(n-1)%MOD) + (countDerangements(n-2)%MOD))%MOD;


    return ans;
}

// being a recursive solution ye TLE dega 

long long int solveMem( int n , vector<long long int> &dp){
    //base case
    if( n == 1){
        return 0 ;

    }
    if( n == 2)         return 1;

    if( dp[n] != -1)    return dp[n];
    //int ans = (n-1)*(countDerangements(n-1) + countDerangements(n-2));
    // par mod krke likhna hai
    int dp[n] = ((n-1)%MOD)*((solveMem(n-1)%MOD) + (solveMem(n-2)%MOD))%MOD;


    return dp[n];
}

// USING TABULATION

long long int solveTab( int n){

    vector<long long int> dp(n+1, 0);

    dp[1] = 0;
    dp[2] = 1;

    for( int i = 3; i < n ; i++){
        long long int first = dp[i-1] % MOD;
        long long int second = dp[i-2] % MOD;
        long long int sum = (first + second) %MOD
        
        long long int ans = ( ( i-1)* sum ) %MOD;
        dp[i] = ans;
    }
    return dp[n];
}

// can we optimise space
// kar skte hn 
long long int solveTab( int n){

    // vector<long long int> dp(n+1, 0);

    long long int prev2 = 0;
    long long int prev1 = 1;
    // dp[2] = 1;

    for( int i = 3; i < n ; i++){
        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int sum = (first + second) %MOD
        
        long long int ans = ( ( i-1)* sum ) %MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}