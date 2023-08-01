/*
also called Cut into segments
 given an integer denoting length of a given rod
 we need to find maximum no. of segments it can be divided into 
 segments of x, y and z
 same like denomination wala question keep cutting the rod 
 till you reach zero length 

*/

// simple recursion 

int solve( int n , int x, int y, int z){
    //base case
    if( n == 0){
        return 0;
    }
    if( n < 0)      return INT_MIN;

    int a = solve( n-x, x, y, z) + 1;
    int b = solve(n-y, x, y, z) + 1;
    int c = solve(n-z, x, y, z) + 1;

    int ans = max( a,max(b,c));

    return ans;


}

int cutSegments( int n , int x, int y, int z){
    int ans = solve(n,x,y,z);
    if( ans < 0)
        return 0;
    else
        return ans;
}
// ye TLE dega 
// TC is exponential

int solveMem( int n, int x, int y, int z, vector<int> &dp){
    // base case
    if( n == 0)
        return 0;

    if( n < 0)
        return INT_MIN;
    
    if( dp[n] != -1)
        return dp[n];

    int a = solveMem( n-x, x, y, z, dp) + 1;
    int b = solveMem( n-y, x, y, z, dp) + 1;
    int c = solveMem( n-z, x, y, z, dp) + 1;

    dp[n] = max( a, max( b, c));
    return dp[n];
}

// lets do dis using tabulation

int solveTab( int n , int x, int y, int z){
    vector<int> dp(n+1, INT_MIN);

    dp[0] = 0;

    for(  int i = 0; i <= 0; i++){
        if( i-x >= 0 && dp[i-x] != -1){ // this is if you are doing using -1 and not INT_MIN
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
        if( i-y >= 0 && dp[i-x] != -1){ // this is if you are doing using -1 and not INT_MIN
            dp[i] = max(dp[i], dp[i-y] + 1);
        }
        if( i-z >= 0 && dp[i-x] != -1){ // this is if you are doing using -1 and not INT_MIN
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }

    if( dp[n] < 0 ){
        return 0;
    }
    else {
        return dp[n];
    }
}

// PAR KYA apan INT_MIN ki jagah -1 kyu nhi use krhe 
// kyuki i-x +1 zero bhi de skta hai 
// kar skte hn -1 ko use krke just modify the if condition see the modified one

// AUR SPACE OPTIMISE KAR SKTE HN KYA
// hame nhi pta x, y, z, kya honge so we cannot do them using variable 
// so space optimisation in not possible here
