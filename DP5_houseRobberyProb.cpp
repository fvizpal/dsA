/*
House Robbery Problem
 all houses aranged in circle // first and last house are neighbours
 if two adjacent houses broken => busted

 given an array representing money in each house
 return maximum money that can be robbed


 approach{
    same peeche wale question ki tarah but here 
    FIRST AND LAST ARE NEIGHBOUR HERE
    so NO !!

    so ye ek condition handle karni hai
    first include kiya hai toh last nhi krna hai 
    so except last; solve rest
    last include kiys hai toh fist nhi krna hai toh 
    except first; solve rest

    now take maximum of both the answers

    do vector bnaao excepting forst the other excepting last

 }
*/
long long int solveTabSpaceOptimal( vector<int> &nums){
    long long int n = nums.size();
    // vector<int> dp(n,0);

    long long int prev2 = 0;

    long long int prev1 = nums[0];

    for( int i = 1; i < n; i++){
        long long int incl = prev2 + nums[i];
        long long int excl = prev1 + 0;
        // dp[i] = max(incl, excl);
        long long int ans = max( incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;// instead of dp[n];

}
long long int houseRobbery( vector<int> valueInHouse){

    int n = valueInHouse.size();
    if( n == 1){
        return valueInHouse[0];

    }

    vector<int> first, second;
    for( int i = 0; i<n; i++){
        if( i != n-1)
            return first.push_back(valueInHouse[i]);
        if( i != 0)
            return second.push_back( valueInHouse[i]);
    }

    return max( solveTabSpaceOptimal(first), solveTabSpaceOptimal(second));
}
// TC O(n);
// SC O(n);

