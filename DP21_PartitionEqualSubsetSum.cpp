/* o> Partion equal subset sum
 *Given N sizeof arr and arr ;
 can we divide this arr into two sub arrays do that sum of them is equal
 *Output true of false ;

 > sare lements ka sum nikaal lete hain fir hamare subset ka sum iss sum ka half hona chahiye
 toh agar off hua toh impossible so output NO

*/
bool solve( int index, vector<int> arr, int N, int target){

    //base case
    if( index >=N) return 0;

    if( taget < 0) return 0;

    if( target == 0) return 1;

    bool include = solve( index+1, arr, N, target - arr[index]);
    bool exclude = solve( index+1, arr, N, target - 0);

    return include or exclude;  

}
bool equalSumPartition(int N, int arr[]){
    int total = accumulate(arr.begin(), arr.end(), 0);
  
    if( total & 1) return false;
    
    int target = total / 2 ;
    
    return solve(0, arr, N, target);  // 0 is initial index
} 
// TLE aayega


// MEMOISATION
bool solveMem( int index, vector<int> arr, int N, int target,vector<vector<int>> dp){

    //base case
    if( index >=N) return 0;

    if( taget < 0) return 0;

    if( target == 0) return 1;

    if( dp[index][target] != -1){
        return dp[index][target]
    }

    bool include = solveMem( index+1, arr, N, target - arr[index]);
    bool exclude = solveMem( index+1, arr, N, target - 0);

    return dp[index][target] = include or exclude;  
}
bool equalSumPartition(int N, int arr[]){
    int total = accumulate(arr.begin(), arr.end(), 0);
  
    if( total & 1) return false;
    
    int target = total / 2 ;
    vector<vector<int> dp(N, vector<int>(target+1, -1));
    
    return solveMem(0, arr, N, target, dp);  // 0 is initial index
} 


//TABULATE
bool solveTab(vector<int> arr, int N, int target){

    vector<vector<int> dp(N+1, vector<int>(target+1, 0)) // pehle do base case ho higye 

    for( int i = 0; i <= N; i++ ){  // equivalent to third base case
        dp[i][0] = 1;
    }

    for( int index = N-1; index >= 0; index--){
        for( int targ = 0; tar <= target; target++){

            if(target- arr[index] >= 0)
                bool include = dp[index+1][target - arr[index]];

            bool exclude = dp[index+1][target - 0];
           
            dp[index][target] = include or exclude;
        }
    }

    return dp[0][target];  
}
bool equalSumPartition(int N, int arr[]){
    int total = accumulate(arr.begin(), arr.end(), 0);
  
    if( total & 1) return false;
    
    int target = total / 2 ;
    // vector<vector<int> dp(N, vector<int>(target+1, -1));
    
    return solveTab(arr, N, target);  // 0 is initial index
}

//SPACE OPTIMISATION
bool solveSO(vector<int> arr, int N, int target){

    vector<vector<int> curr(target + 1, 0); // pehle do base case ho higye 
    vector<vector<int> next(target + 1, 0); // pehle do base case ho higye 

        // equivalent to third base case
        curr[0] = 1;
        next[0] = q;

    for( int index = N-1; index >= 0; index--){
        for( int targ = 0; tar <= target; target++){

            if(target- arr[index] >= 0)
                bool include = next[target - arr[index]];

            bool exclude = next[target - 0];
           
            curr[target] = include or exclude;
        }
        next = curr;
    }

    return next[target];
}
bool equalSumPartition(int N, int arr[]){
    int total = accumulate(arr.begin(), arr.end(), 0);
  
    if( total & 1) return false;
    
    int target = total / 2 ;
    // vector<vector<int> dp(N, vector<int>(target+1, -1));
    
    return solveSO(arr, N, target);  // 0 is initial index
}
//