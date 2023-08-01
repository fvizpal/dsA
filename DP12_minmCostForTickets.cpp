/*
Minimum cost for tickets
 given a days arrayc consisting of N days  1 se 365 
 and cost array 

 minimum cost kya hogi travel krni ki

 kisi bhi day p teen option hai ya mai 1-day pass lu ya 7-day ya 30-day
 teeno ki cost cost array me di gyi hai 

 i array se bahar nikal jaye toh base case reach ho chuki hai 
 
*/

int solve ( int n, vector<int> &days, vector<int> &cost, int index){

    //base case
    if( index >= n){
        return 0;
    }

    //1 day pass
    int option1 = cost[0] + solve(n, days, cost, index+1);

    int i;
    //7 day pass
    for( int i = index; i < n && days[i] < days[index] + 7; i++);

    int option2 = cost[1] + solve(n, days, cost, i);
    
    //30 day pass
    for( int i = index; i < n && days[i] < days[index] + 30; i++);

    int option3 = cost[3] + solve(n, days, cost, i);

    return min( option1, option2, option3);
    
}

int minimumCost( int n, vector<int> days, vector<int> cost){
    return solve( n, days, cost, 0);
}


// MEMOIZATION

int solveMem ( int n, vector<int> &days, vector<int> &cost, int index, dp){

    //base case
    if( index >= n){
        return 0;
    }

    if( dp[index] != -1){
        return dp[index];
    }

    //1 day pass
    int option1 = cost[0] + solve(n, days, cost, index+1, dp);

    int i;
    //7 day pass
    for( int i = index; i < n && days[i] < days[index] + 7; i++);

    int option2 = cost[1] + solve(n, days, cost, i, dp);
    
    //30 day pass
    for( int i = index; i < n && days[i] < days[index] + 30; i++);

    int option3 = cost[3] + solve(n, days, cost, i, dp);

    dp[index] = min( option1, min(option2, option3));
    return dp[index];
}

int minimumCost( int n, vector<int> days, vector<int> cost){
    vector<int> dp(n+1, -1);
    return solve( n, days, cost, 0, dp);
} // TC is O(1) wow

//TABULATION

int solveTab( int n , vector<int> days, vector<int> cost){

    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;

    for( int k = n-1; k >= 0; k--){
        //1 day pass
        int option 1 = cost[0] + dp[k+1];

        int i;
        // 7 day pass
        for( i = k; i< n && days[i] < days[k] + 7; i++);

        int option2 = cost[1] + dp[i];

        //30 day pass
        for( i = k; i < n && days[i] < days[k]+30; i++);

        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }

    return dp[0];
}
//TC is O(n)
//SC is O(n) too


//PART 2

//Space OPtimisation
// this will be more of a classy space optimisation , we ll use queue 
// par iss queue ki size apan ko pata hoga  toh ye ocnstant space hi hoga
/*
 step1 : remove expired days from queue
 step 2: push correct days cost ... push(pair<day, ans + cost[1]);
            similarly push into monthly wala
 step 3: upadate answer
            ans = min( ans + cost[0], min(monthly ))
 
*/
int minimumCost( int n , vector<int> days, vector<int> cost){

    // int ans  = INT_MAX;  // yha zero rahega nhi toh wring answer
    int ans = 0;

    queue<pair<int,int>> month;
    queue<pair<int,int>> week;

    for( int day : days){
        //step 1: remove expired days
        while( !month.empty() && month.front.first + 30 <= day){
            month.pop();
        }

        while( !week.empty() && week.front.first + 7 <= day ){
            week.pop();
        }

        //step 2: add cost for current day
        week.push( make_pair(day, ans+cost[1]));
        month.push( make_pair(day, ans+cost[2]));

        //step 3: ans update
        ans = min( ans + cosst[0], min(week.front().second , month.front().second));

    }

    return ans;
}
