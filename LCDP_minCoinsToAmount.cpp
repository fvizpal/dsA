// 322. 

 // 1.
int mini = INT_MAX;
int coinChange( vector<int> &coins, int amount){
    if( coins.size() == 0 or amount == 0) return 0;

    sort( coins.begin(), coins.end());
    
    dfs(coins, coins.size()-1, amount, 0);
    
    if( mini == INT_MAX) return -1;

    return mini;
}
void dfs( vector<int> & coins,int ind, int amount, int cnt){
    if( ind == -1) return ;

    int number = amount/coins[ind];
    for( int = number; i >= 0; i--){
        int remain = amount - coins[ind]*i;
        int newcnt = cnt + i;
        
        if( remain > 0 and newcnt < mini){
            dfs( coins, ind-1, remain, newcnt);
        }
        else if( newcnt < mini){
            mini = newcnt;
        }
        else break;
    }
}
// gave TLE


// 2.
int solve( vector<int> coins, int curr, int amount){
    if( curr >= coins.size() or amount <= 0) {
        return ( amount == 0) ? 0 : INT_MAX - 1;
    }

    int res = -1;
    if( coins[curr] > amount) {
        int notTake = 0 + solve(coins, curr + 1, amount - 0);
        res = notTake;
    }
    else{
        int take = 1 + solve(coins, curr + 0, amount - coins[curr]);
        int notTake = 0 + solve( coins, curr+1, amount - 0);
        res = min( take, notTake);
    }

    return res;
}
int coinChange( vector<int> coins, int amount){
    int res = solve(coins, 0, amount);
    return (res == INT_MAX-1) ? -1 : res;
}

//3. Tabulated
int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp( coins.size()+1, vector<int>( amount+1, INT_MAX-1));
    
    for(int i = 0; i < coins.size()+1; i++){
        dp[i][0] = 0;
    }

    for( int i = 1; i < coins.size()+1; i++){
        for( int j = 1; j < amount+1; j++){
            if( coins[i-1] > j){
                dp[i][j] = 0 + dp[i-1][j];
            }
            else{
                dp[i][j] = min( 0 + dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
            }
        }
    }

    return (dp[coins.size()][amount] == INT_MAX-1) ? -1 : dp[coins.size()][amount];
}