/*
Combination sum IV problem
 Given an array of distinct integers we need to make combinations with sum equal to target

*/
int solve( vector<int> &num, int tar){
    //base case
    if( tar < 0)       return 0;

    if( tar == 0)       return 1;

    int ans = 0;

    for( int i = 0; i < num.size(); i++){
        ans += solve( num, tar - num[i]);
    }

    return ans;
}

int findWays(vector<int> &num, int tar){
    return solve( num, tar);
}

// BUT WILL GIVE TLE SINCE EXPONENTIAL TC

int solveMem( vector<int> &num, int tar){
    if( tar < 0)
        return 0;
    if( tar == 0)
        return 1;
    
    if( dp[tar] != -1){
        return dp[tar];
    }

    int ans = 0;
    for( int i =0; i < num.size(); i++){
        ans += solveMem( num, tar-num[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}
int findWays( vector<int> &num, int tar){

    vector<int> dp( tar+1, -1);
    return solveMem( num, tar, dp);
}// TC is O(target)

//LETS NOW TABULATE 

int solveTab( vector<int> &num, int tar){

    vector<int> dp(tar +1, 0);
    dp[0] = 1;

    //traversing for 1 to tar
    for( int i =1 ; i <= tar; i++){

        //traversing on num array
        for( int j = 0; j < num.size();; j++){
            if( i-num[j] >= 0)
                dp[i] += dp[i-num[j]]; 
        }
    }
    return dp[tar];
}
int findways( vector<int> &num, int tar){

    return solveTab( num, tar);
}
//TC is O(n*m)

//SPACE OPTIMIZATION
dp[i] yha depend kar rha hai dp[i-num[j]]
 but ye nhi pta i kispe depend karega 
 toh NHI HO PAYEGA