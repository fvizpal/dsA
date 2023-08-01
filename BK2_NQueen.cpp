/*
N-Queen Puzzle
 place N queens on N*N chessboard such that no two queens attack each other

 approach{
    each row and column have one queen 
    and no two attack each other
    we have a matrix at start
    to place in column 1 ; there will be 4 choices
    now each of these 4 choices will themselves have dependent choices for placement
    of queen at column 2
    backtracking yha aise hui ki jab kisi cycle m ghuse or vo galat ho tb wapis aate hue queen ko ham uss galat 
    place se remove kr  denge 

    ye bhi ham recursion se krenge ; that is solving one case baki apne aap ho jayega check
    

 }
  // queens ko 1 se show kr rhe hn aur empty space ko 0 se
*/

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n ){

    vector<int> temp;

    for( int i = 0 ; i< n ; i++){
        for( int j= 0; j< n ; j++){
            temp.push_back(board[i][j])
        }
    }

    ans.push_back(temp);
}

bool isSafe( int row , int col, vector<vector<int>> &board, int n ){
    // bs attack nhi krni chahiye
    int x = row;
    int y = col;

    // check for same row
    while( y >= 0){
        if( board[x][y] == 1){
            return false;
        }
        y--;
    }
    x = row;
    y = col;
    //check for diagnol
    while(x > 0 && y > 0){
        if( board[x][y] == 1){
            return false;
        }
        y--;
        x--;
    }
    while(x < n && y > 0){
        if( board[x][y] == 1){
            return false;
        }
        y--;
        x++;
    }
}

void solve( int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    //base case
    if( col == n){ // jo bhi board me solution bna pda hai usse hame answer m dalna hai
        addSolution(board, ans);
        return;
    }

    // solve 1 case ;; rest recursion
    for( int row = 0; row < n ; row++){
        if( isSafe(row,col, board, n)){
            // if placing queen is safe
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            //backtrack
            board[row][col] = 0; // wapis aao toh backtrack krte hue hata dena
        }
    }


}

vector<vector<int>> nQueens(int n ){

    vector< vector<int>> board( n, vector<int> (n,0));
    vector< vector< int>> ans;
    solve ( 0, ans, board, n);

    return ans;
}//optimization 
// using hashmaps to check agar queen pdi hai ki nhi in a row

// sc optimise hojayega
// TC is O( n! )