/* 
Larget square in a matrix
 given a matrix of 0 's and 1's 
 what will the maximum size 
 square sub matrix of 1's in the given matrix
 
 to form a square check first that the diagnol one is 1 then check if verticle and horizontal ones are also one till the edge


*/
int solve( vector<vector<int>> mat, int i , int j, int &maxi){
    if( i >= mat.size() || mat[0].size()){
        return 0;
    }
    int right = solve( mat, i , j+1,maxi);
    int diagnol = solve( mat, i+1, j+1, maxi);
    int down = solve( mat, i+1, j, maxi);

    if( mat[i][j] == 1){
        int ans = 1+ min( right, min( diagnol, down));
        maxi= max( maxi, ans);
        return ans;
    }
    else{
        return 0;
    }

}
int maxSquare( int n, int m, vector<vector<int>> mat){
    int maxi;
    solve( mat, 0, 0, maxi);
    return maxi;
}
// TLE dega

// MEMOIZATION - top down approach
int solveMem( vector<vector<int>> &mat, int i , int j, int &maxi, vector<vector<int>> &dp){
    if( i >= mat.size() || mat[0].size()){
        return 0;
    }

    if( dp[i][j] != -1)     return dp[i][j];

    int right = solveMem( mat, i , j+1,maxi, dp);
    int diagnol = solveMem( mat, i+1, j+1, maxi, dp);
    int down = solveMem( mat, i+1, j, maxi, dp);

    if( mat[i][j] == 1){
        int dp[i][j] = 1+ min( right, min( diagnol, down));
        maxi= max( maxi, dp[i][j]);
        return dp[i][j];
    }
    else{
        return dp[i][j] = 0;
    }

}
int maxSquare( int n, int m, vector<vector<int>> mat){
    
    int maxi;
    vector<vector<itn>> dp(n,vector<int>(m,-1));
    solveMem( mat, 0, 0, maxi, dp);
    return maxi;
}

// TABULATION - bottom up approach
int solveTab( vector<vector<int>> &mat, int &maxi){
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> dp( row, vector<int> (col, 0));

    for( int i = row -1; i>= 0; i--){
        for( int j = col-1; j>= 0; j--){
            int right = dp[i][j+1];
            int diagnol = dp[i+1][j+1];
            int down = dp[i+1][j];

            if( mat[i][j] == 1){
                dp[i][j] = 1 + min( right, min( diagnol, down));
                maxi = max( maxi, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[0][0];
}
int maxSquare( int n , int m, vector<vector<int>> mat){

    int maxi = 0;
    solveTab( mat, maxi);
    return maxi;
}
//TC  is O(m*n);
//SC  is O(m*n);

//SPACE OPTIMIZATION
//dp array ki zaroorat h nahi 
// sahi se dekho toh current row or next row ka hi kaam hai
int solveSO( vector<vector<int>> &mat, int &maxi){
    int row = mat.size();
    int col = mat[0].size();

    //vector<vector<int>> dp( row, vector<int> (col, 0));
    // iski nahi zaroorat
    vector<int> curr( col+1, 0);
    vector<int> next( col+1, 0);

    for( int i = row -1; i>= 0; i--){
        for( int j = col-1; j>= 0; j--){
            int right = curr[j+1];
            int diagnol = next[j+1];
            int down = next[j];

            if( mat[i][j] == 1){
                dp[i][j] = 1 + min( right, min( diagnol, down));
                maxi = max( maxi, curr[j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
        next = curr;
    }
    return next[0];
}
// here SC IS O(m); // or row
// similarly O(n) me bhi solve kar skte hain


