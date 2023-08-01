/*
Given stairs
 starting from oth stair we need to reach nth stair
 can take only one step at a time or 
 2 steps at a time

 recursion se kar skte hn 
 at every step you have 2 choices

*/

// the recursive way
#define MOD 1000000007
int solve( long long nStairs, int i ){ // i yha current stair ko dikhata hai
    //base case
    if( i == nStairs){
        return 1; // no of ways to reach your destination when you are at the destination is 1
    }

    if( i > nStairs){
        return 0; // ye invalid wala case hai 
    }

    return (solve(nStairs, i+1) + solve(nStairs, i+2)) & MOD; // isse modulus me hi return krna hota hai 
    //mtlb ya toh ek step aage bad ke aya hoga ya(+) do step aage bad k 
}

int countDistinctWayToClimbStair(long long nStairs){

    int ans = solve(nStairs, 0); //start from 0
    return ans ;
}

// but ye TLE maar jayega
// yha bhut saari overlapping sub problems hn 
// so use DP 

/*
Minimum cost of climbing stairs
 har ek stair pe khade rehne ka cost ek array me diya hoga 
 you have choice of either taking one step at a time or two
 we have to pay cost of each step only then we can move ahead
 we need to find minm cost of reaching top stair

 nth step ki cost include nhi hogi wese iski cost de bhi nhi rkhi

*/

int solve( vector<int> &cost, int n){
    //base case
    if( n == 0)     return cost[0];
    if( n == 1)     return cost[1];

    int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    return ans;
}

int minCostClimbingStairs( vector<int> &cost){
    int n = cost.size();
    int ans = min(solve(cost, n-1), solve(cost, n-2));
    return ans;
} //  but TLE aa jayega isme 
 // isme recursion toh kar diya hai .. pr memoisation add krni hai


int solve2( vector<int> &cost, int n, vector<int> dp){
    //base case
    if( n == 0)     return cost[0];
    if( n == 1)     return cost[1];

    //step 3
    if( dp[n] != -1)    return dp[n];

    //step 2
    int dp[n] = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    return dp[n];
}

int minCostClimbingStairs( vector<int> &cost){
    // int n = cost.size();
    // int ans = min(solve(cost, n-1), solve(cost, n-2));
    // return ans;

    int n = cost.size();
    // step1 
    vector<int> dp( n+1, -1); // initialising the dp with -1
    int ans = min ( solve2(cost, n-1, dp), solve2(cost, n-2,dp))
    return ans;
}

    // BOTTOM DOWN approach bhi dekh lete hn
    // isme hame tabulation bnana hoga

// yha p jo chiz change horhi vo kya hai , only n;
// na cost or na hi dp array change horha 
// toh hame ek 1 D array ki zaroorat padegi

int solve3( vector<int> &cost, int n){
    //1st
    vector<int> dp(n+1);
    
    //2nd step these are the base cases
    dp[0] = cost[0];
    dp[1] = cost[1];

    //3rd step
    for( int i = 2; i < n ; i++){
        dp[i] = cost[i] + min( dp[i-1], dp[i-2]);

    }

    return min( dp[n-1], dp[n-2]);
}

int solve4( vector<int> &cost, int n){
    //1st
    // vector<int> dp(n+1); iski zaroorat nahi
    
    //2nd step these are the base cases
    int prev2 = cost[0];
    int prev1 = cost[1];

    //3rd step
    for( int i = 2; i < n ; i++){
        int curr = cost[i] + min( prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
        // dp[i] = cost[i] + min( dp[i-1], dp[i-2]);

    }

    return min( prev1, prev2);
}
int minCostClimbingStairs(vector<int> &cost){
    int n = cost.size();
    return solve3(cost , n);
}


in memoisation
// TC kitni hui iski O( n ) 
// SC O(n) + O(n)

in tabulation
// TC and SC both are O(n)

par tabulation m hame do hi number toh track krne hn toh vo toh do variable me bhi ho jayenge
// toh do dat // solve4 wala func shows dat
yha SC O(1) hogya or TC O(n) toh hai hi

