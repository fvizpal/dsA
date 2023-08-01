/*
Pizza with 3n slices
 friends will take slices of pizza asjacent to right and left 
 the step is repeated
 
 house robbery problem yad arhi hogi
 
*/
int solve( int index, int endInd, vector<int> &slices, int n){
    //base case
    if( n == 0 || index > endInd){
        return 0;
    }

    int take = slices[index] + solve(index+2,endInd slices, n-1);
    int notTake = 0 + solve(index+1,endInd slices, n);

    return max(take, notTake);
}
int maxSizeSlices(vector<int> &slices){
    int k = slices.size();
    int case1 = solve(0, k-2, slices, k/3);
    int case2 = solve(1, k-1, slices, k/3);

    return max( case1, case2);
} // TLE maarega


MEMOIZATION - top down

int solveMem( int index, int endInd, vector<int> &slices, int n){
    //base case
    if( n == 0 || index > endInd){
        return 0;
    }
    if( dp[index][n] != -1){
        return dp[index][n];
    }

    int take = slices[index] + solveMem(index+2,endInd slices, n-1, dp);
    int notTake = 0 + solvemem(index+1,endInd slices, n, dp);

    return dp[index][n] = max(take, notTake);
}
int maxSizeSlices(vector<int> &slices){
    int k = slices.size();
    vector<vector<int>> dp1(k, vector<int>(k, -1)); // for case 1
    vector<vector<int>> dp2(k, vector<int>(k, -1)); // for case 2

    int case1 = solveMem(0, k-2, slices, k/3, dp1);
    int case2 = solveMem(1, k-1, slices, k/3, dp2);

    return max( case1, case2);
} // 

TABULATION

int solveTab(vector<int> &slices){
    int k = slices.size();
    vector<vector<int>> dp1(k+2, vector<int>(k, 0)); // for case 1

    for( int i = k-2; i >= 0; i--){
        for( int n = 1; n <= k/3; n++){
            int take = slices[index] + dp1[index+2][n-1];
            int notTake = 0 + dp1[inedx+1][n];

            dp1[inedx][n] = max(take, notTake);
        }
    }
    int case1 = dp1[0][k/3];

    vector<vector<int>> dp2(k+2, vector<int>(k, 0)); // for case 2
    for( int i = k-1; i >= 1; i--){
        for( int n = 1; n <= k/3; n++){
            int take = slices[index] + dp2[index+2][n-1];
            int notTake = 0 + dp2[inedx+1][n];

            dp2[inedx][n] = max(take, notTake);
        }
    }
    int case2 = dp2[0][k/3];

    return max(case1, case2);
}
int maxSizeSlices(vector<int> &slices){
    return solveTab(slices);
} //  



SPACE OPTIMIZED

int solveTab(vector<int> &slices){
    int k = slices.size();
    vector<int > prev1(k+2, 0);
    vector<int > curr1(k+2, 0);
    vector<int > next1(k+2, 0);

    for( int i = k-2; i >= 0; i--){
        for( int n = 1; n <= k/3; n++){
            int take = slices[index] + next1[n-1];
            int notTake = 0 + curr1[n];

            prev1[n] = max(take, notTake);
        }
        next1 = curr1;
        curr1 = prev1;
    }
    int case1 = curr1[k/3];

    vector<int> prev2(k+2, 0);
    vector<int> curr2(k+2, 0);
    vector<int> next2(k+2, 0);

    for( int i = k-1; i >= 1; i--){
        for( int n = 1; n <= k/3; n++){
            int take = slices[index] + next[n-1];
            int notTake = 0 + curr2[n];

            prev2[n] = max(take, notTake);
        }
        next2 = curr2;
        curr2 = prev2;
    }
    int case2 = curr2[k/3];

    return max(case1, case2);
}