/*
approach
 to begin with we shall have an empty string
 we need to print in lexicographical order 
 that is the sorted path
 at start we are on 0,0
 the next block we want to visit shld not have been already visited
 and our path shld be within safe region that is within the matrix
 as we leave a block, mark the blocks : visited = true
 note, we have two matrix ; one to check if a block has been visited
 
*/

void isSafe(  ){ // the next block should not have been visited and the path should be within the matrix range
    
    
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &vis, string path){
    //base case
    if( x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    //the 4 movements // D, L, U, R
    vis[x][y] = 1; // marking current block as visited
    //down
    if(isSafe(x+1, y, vis, arr, n)){
        solve(x+1, y, arr, n ,ans, vis, path + 'D');
    }
    //left
    if(isSafe(x, y-1, vis, arr, n)){
        solve(x, y-1, arr, n ,ans, vis, path + 'L');
    }
    //right
    if(isSafe(x, y+1, vis, arr, n)){
        solve(x, y+1, arr, n ,ans, vis, path + 'R');
    }
    //up 
    if(isSafe(x-1, y, vis, arr, n)){
        solve(x-1, y, arr, n ,ans, vis, path + 'U');
    }
    // these 4 movements code can be made smaller using for loop


    vis[x][y] = 0;
}

vector< string> searchMaze( vector<vector<int>> &arr, int n  ){
    vector<string> ans;
    vector<vector<bool>> visited( n, vector<bool> (n,0));
    //The code initializes all the elements in the vector to false using the vector<bool> (n,0) syntax. 
    //This creates a 1D vector of boolean values with n elements, all initialized to false. The 1D vector is then used to initialize each row in the 2D vector.// WhatTheF
    
    string path = "";
    if( arr[0][0] == 0 )    return ans;

    solve( 0,0 , arr, n, ans, visited, path);

    retun ans;
}

// TC is O( 4^(n*n) )and SC is O( n*m)