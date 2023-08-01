/*
Minimum score triangulation of polygon
    'based on matrix chain multipplication'
 given a polygon , and weights of vertices -
 divide the polygons by adding lines through vertices such that all are triangles
 
*/
int solve( vector<int> &v, int i , int j){
    //base case
    if( i+1 == j){
        return 0;
    }

    int ans = INT_MAX;
    for( int k = i+1; k < j; k++){
        ans = min( ans, v[i]*v[j]*v[k] + solve(v,i,k) + solve(v, k,j) );
    }
    return ans;
}
int minScoreTriangulation( vector<int> &values){
    int n = values.size();
    return solve( values, 0, n-1);
}
// TLE aayega - simple recursion hai


//MEMOIZATION
int solveMem( vecto<int> &v, int i , int j, vector<vecotr<int>> &dp){
    //base case
    if( i+1 == j){
        return 0;
    }

    if( dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = INT_MAX;
    for( int k = i+1; k< j; k++){
        ans = min( ans, v[i]*v[j]*v[k] + solveMem(v,i,k, dp) + solveMem(v, k,j, dp));
    }
    dp[i][j] = ans;

    return dp[i][j];
}
int minScoreTriangulation( vector<int> &values){
    int n = values.size();
    vecto<vector<int>> dp(n, vector<int> ( n, -1));
    return solve( values, 0, n-1, dp);
}// TC is O()

//TABULATION
int solveTab( vector<int> &v){

    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for( int n-1; i>= 0 ; i--){
        for( int j =  i+2; j <= n; j++){

            int ans = INT_MAX;
            for( int k = i+1; k< j; k++){
                ans = min( ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;

        }
    }
    return dp[0][n-1];

}
int minScoreTriangulation( vector<int> &values){
    int n = values.size();
    return solveTab( values);
}


//SPACE OPTIMIZATION
// yha 
// gap strategy se bhi ye kar skte hain