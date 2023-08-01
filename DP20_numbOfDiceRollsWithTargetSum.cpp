/* o> Number of dice rolls with target sum
 ** This and further 3 questions will be based on DP with distinct ways

 Given N dices with M faces; find number of distinct ways to get SUM
 X is summation of face value of all dice
 
 input : n,m,x;
 output : no. of ditinct ways

 jis bhi dice pe aayenge uske saare hi faces tty karenge 
*/
//                   // N      // M      // sum
long long noOfWays(int dice, int faces, int target){

    //base case
    if( target < 0) return 0;
    if( dice  == 0 && taget != 0) return 0;
    if( target == 0 && dice != 0) return 0;
    if( dice == 0 && target == 0) return 1; // kuch mat kro fir sum ban jayega so 1
    
    // jis dice pe hain uske daare faces utilise karna hai
    int ans = 0;
    for( int i = 1; i <= faces; i++){
        ans = ans + noOfWays(dice-1, faces, target - i);
    }

    return ans;
} // TLE aana chahiye


// MEMOIZATION
long long solveMem(int dice, int faces, int target, vector<vector<long long>> &dp){

    //base case
    if( target < 0) return 0;
    if( dice  == 0 && taget != 0) return 0;
    if( target == 0 && dice != 0) return 0;
    if( dice == 0 && target == 0) return 1; // kuch mat kro fir sum ban jayega so 1
    

    if( dp[dice][target] != -1){
        return dp[dice][target];
    }

    // jis dice pe hain uske daare faces utilise karna hai
    long long ans = 0;
    for( int i = 1; i <= faces; i++){
        ans = ans + solveMem(dice-1, faces, target - i, dp);
    }

    return dp[dice][target] = ans;
}

long long noOfWays(int N, int M, int X){ // do parameter ki sstate change horhi hai isliye 2D dp
    vector<vector<long long>> dp(N+1, vector<int>(X+1, -1));
    return solveMem(N, M, X, dp);
} //TC O(  )



// TABULATE - Bottom up 
long long solveTab( int dice, int faces, int target){
    vector<vector<long long>> dp(dice+1, vector<int>(taget+1, 0));
    
    // starting ke 3 base cases initialisaton me hi cover hogye
    dp[0][0] = 1; // ye 4th base case hua

    for( int dic = 1; dic <= dice; dic++){  // 0 's ke liye kyuki pehle se nikala hai
        for( int targ = 1; targ <= target; targ++){
            long long ans = 0;
            for( int i = 1; i <= faces; i++){
                if( target - i >= 0)  // handling invalid indices
                    ans = ans + dp[dice-1][target-i];
            }

            dp[dice][target] = ans;
        }
    }

    return dp[dice][target];
}// TC O( N * M * X)    SC O( N*X)


//SPACE OPTIMISED;
// depends only on pichli wali row  O( X ) space ki hi zaroorat hai
long long solveTab( int dice, int faces, int target){
    // vector<vector<long long>> dp(dice+1, vector<int>(taget+1, 0));
    vector<long long> prev(target+1);
    vector<long long> curr(target+1);
    
    // starting ke 3 base cases initialisaton me hi cover hogye
    prev[0] = 1; // ye 4th base case hua

    for( int dic = 1; dic <= dice; dic++){  // 0 's ke liye kyuki pehle se nikala hai
        for( int targ = 1; targ <= target; targ++){
            long long ans = 0;
            for( int i = 1; i <= faces; i++){
                if( target - i >= 0)  // handling invalid indices
                    ans = ans + prev[target-i];
            }

            // dp[dice][target] = ans;
            curr[taget] = ans;
        }
        prev = curr;
    }

    // return dp[dice][target];
    return prev[target];
}// TC O( N * M * X)    SC O( X)