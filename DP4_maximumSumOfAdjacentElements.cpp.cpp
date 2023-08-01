/*
maximum sum of non adjacent elements
 given an array of n integers
 return max sum but no two elements shall be adjacent
 
 approach{
    at every pointer to the elemnet we will have choice to either include or exclude the element
    on inclusion we will move the pointers by i+2 and add it to sum
    on exclusion we wil move by one and add zero to sum

 }
*/

// the simple recursive method 

int solve( vector<int> &nums, int n ){

    // base case
    if( n < 0)      return 0;
    if( n == 0)     return nums[0];

    int incl = solve(nums, n-2) + nums[n];
    int excl = solve(nums, n-1) + 0;

}

int maxnonAdjacentSum( vector<int> &nums){
    int n = nums.size();
    int ans = solve(nums, n-1);

    return ans;
}

// may get TLE // TC is exponential

// lets add memo

int solveMem( vector<int> & nums , int n , vector<int> &dp){
    //base case
    if( n < 0 )     return 0;
    if( n == 0)     return nums[0];

    if( dp[n] != -1){
        return dp[n];
    }

    int incl = solve(nums, n-2) + nums[n];
    int excl = solve(nums, n-1) + 0;

    dp[n] = max(incl, excl);
    return dp[n];
}

int maxnonAdjacentSum(vector<int> & nums){

    int n = nums.size();
    vector<int> dp(n, -1);
    return solveMem( nums, n-1, dp);

}
// TC is O( n )  // SC is of ( dp array) + (recursive stack ka space) i.e. O(n)+ O(n)
// but this will also give TLE 

// so lets Tabulate now

int solveTab( vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,0);

    dp[0] = nums[0];

    for( int i = 1; i < n; i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl, excl);
    }

    return dp[n];

}
int solveTabSpaceOptimal( vector<int> &nums){
    int n = nums.size();
    // vector<int> dp(n,0);

    int prev2 = 0;

    int prev1 = nums[0];

    for( int i = 1; i < n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        // dp[i] = max(incl, excl);
        int ans = max( incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;// instead of dp[n];

}
int maxnonAdjacentSum( vector<int> &nums){
    return solveTab(nums);
}
// here TC wld be O( n ) and O( n )

// KYA space optimise kra jaa skta hai 

// dp[i] element edepends on incl and excl variable that is dp[ i - 2] and dp[i-1]
// only peeche ke do se matlab hai 

// Toh haan ! do variable use krke kar skte hn!

