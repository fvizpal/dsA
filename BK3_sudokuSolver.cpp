/*
sudoku Solver
 given a 9*9 matrix
 empty cells are filled with 0s and rest are filled with integers form 1 to 9
 fill emoty cells such that final solution represents a sudoku solution

 approach{
    recursively :
    ek m daal k dekh lo if it is valid
    baki smbhal lega

    if invalid ; we will backtrack ; that is again make it zero
 }
 TC is O(9^m) SC is O(1) ;; had se had 81 recursive call jayengi 
*/

bool isSafe( int row, int col, vector<vector<int>> &board, int val){
    for( int i=0; i< board.size(); i++){
        //row check
        if( board[row][i] == val)   return false;
        //col check
        if( board[i][col] == val)   return false;
        //33 matrix check
        if( board[3*(row/3) + i/3][3*(col/3) + i%3] == val){ // isse smjho
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board){
    int n = board[0].size();

    for( int row = 0; row < n; row++){

        //cell empty
        if( board[row][col] == 0){
            for( int val = 1; val <= 9; val++){
                if( isSafe(row,col,board,val)){
                    board[row][col] = val;
                    //recursive call
                    bool aageSolutionPossible = solve(board);
                    if( aageSolutionPossible){
                        return true;
                    }
                    else{
                        //backtrack
                        board[row][col] = 0;
                    }
                }
            }
            return false;
        }
    }
    return true;
}