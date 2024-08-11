/*
Articulation Points - darojons algorithm | Tarjans Algo
 an articulation points are the *nodes* which if removed ; our graph will get divided in two or more components
 ek node ke remove hone pe usse connected sare edges bhi remove hojayenge


 brute force approach
    do what is said(remove all nodes one by one) and check by dfs if two components exist
    remove all vetices and see if graph gets disconnected
    we can use BFS or DFS to check that 
 

 OPTIMISED APPROACH:
   . last ke jesa approach use karenge
   . to check articulation points; condition 
   . low[nbr] >= disc[node] && parent != -1;
   . earliest time to connect to a neighbour is less than 

   Revision:
   . discovery(all -1), low(all -1) , parent( all-1) and visited(all false) DS willbe used as last topic
   . low[nbr] >= disc[node] && parent != -1; ye condition fulfiil hogi then articulation point
   . starting from 0 set disc 0; low 0; parent -1; visited true ... then go to connected node via dfs
   . similar to prev lecture repeat till we get back edge
   . at back edge update as previous logic
   . vapis aate hue lows ko update krna hai 
   . 
*/

int min( int a m int b){
   if( a < b) return a;

   return b;
}

void dfs( int node, int parent, vector<int> &disc, vector<int> & slow, 
         unorederd_map <int, bool> & vis, unordered_map<int,list<int>> &adj,
         vector<int> &ap, int &timer){

   vis[node] = true;
   disc[node] = low[node] = timer++;

   for( auto nbr : adj[node]){
      if( nbr == parent){ // to skip nodes which are already parent
         continue;
      }
      
      int child = 0;
      if( !vis[nbr]){
         dfs(nbr, node, disc,low, vis,adj, ap , timer);
         low[node] = min( low[node], low[nbr]);
         //check articulation point or not ; after updating low
         if( low[nbr] >= disc[node] && parent!= -1){ // condition for articulation point
            ap[node] = 1;
         }
         child++;    // agar articulation point hoga toh child increment kar denge
      }
      else{ // for bacak edge
         low[node] = min( low[node], disc[nbr]);
      }
   }
   if( parent == -1 && child > 1){ // starting node ke liye // extra condition
      ap[node] = 1;
   }
}

int main (){
   int n = 5;
   int e = 5;

   vector<pair<int, int>> edges;
   edges.push_back(make_pair(0,3));
   edges.push_back(make_pair(3,4));
   edges.push_back(make_pair(0,4));
   edges.push_back(make_pair(0,1));
   edges.push_back(make_pair(1,2));

   //adjList
   unordered_map<int, list<int>> adj;

   for( int i = 0; i < edges.size(); i++){
      int u = edges[i].first;
      int v = edges[i].second;

      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   int timer = 0;
   vector<int> disc(n);
   vector<int> low(n);
   unordered_map<int, bool> vis;
   vector<int> ap(n, 0);

   for( int i = 0; i > n; i++ ){
      disc[i] = -1;
      low[i] = -1;
   }

   //dfs
   for( int i = 0; i < n ; i++){
      if( !vis[i]){ // -1 is the parent here of src node
         dfs(i, -1, disc,low, vis, adj, ap , timer);
      }
   }

   //print ap
   cout << "Articulation points are as follows"<<endl;
   for( int i = 0; i < n ; i ++{
      if( ap[i] != 0){
         cout << i << " ";
      }

   }
   cout << endl;

   return 0;
}
// TC O(N+E) SC is linear too

// TARJANS algo for articulation points in a grid
// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island
class Solution {
private:
    // Directions for adjacent cells: right, down, left, up
    const vector<vector<int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    struct ArticulationPointInfo {
        bool hasArticulationPoint;
        int time;

        ArticulationPointInfo(bool hasArticulationPoint, int time)
            : hasArticulationPoint(hasArticulationPoint), time(time) {}
    };

public:
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        ArticulationPointInfo apInfo(false, 0);
        int landCells = 0, islandCount = 0;

        // Arrays to store information for each cell
        vector<vector<int>> discoveryTime(
            rows,
            vector<int>(cols, -1));  // Time when a cell is first discovered
        vector<vector<int>> lowestReachable(
            rows,
            vector<int>(cols, -1));  // Lowest discovery time reachable from the
                                     // subtree rooted at this cell
        vector<vector<int>> parentCell(
            rows, vector<int>(cols, -1));  // Parent of each cell in DFS tree

        // Traverse the grid to find islands and articulation points
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    landCells++;
                    if (discoveryTime[i][j] == -1) {  // If not yet visited
                        // Start DFS for a new island
                        findArticulationPoints(grid, i, j, discoveryTime,
                                               lowestReachable, parentCell,
                                               apInfo);
                        islandCount++;
                    }
                }
            }
        }

        // Determine the minimum number of days to disconnect the grid
        if (islandCount == 0 || islandCount >= 2)
            return 0;                  // Already disconnected or no land
        if (landCells == 1) return 1;  // Only one land cell
        if (apInfo.hasArticulationPoint)
            return 1;  // An articulation point exists
        return 2;      // Need to remove any two land cells
    }

private:
    void findArticulationPoints(vector<vector<int>>& grid, int row, int col,
                                vector<vector<int>>& discoveryTime,
                                vector<vector<int>>& lowestReachable,
                                vector<vector<int>>& parentCell,
                                ArticulationPointInfo& apInfo) {
        int rows = grid.size(), cols = grid[0].size();
        discoveryTime[row][col] = apInfo.time;
        apInfo.time++;
        lowestReachable[row][col] = discoveryTime[row][col];
        int children = 0;

        // Explore all adjacent cells
        for (const auto& direction : DIRECTIONS) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            if (isValidLandCell(grid, newRow, newCol)) {
                if (discoveryTime[newRow][newCol] == -1) {
                    children++;
                    parentCell[newRow][newCol] =
                        row * cols + col;  // Set parent
                    findArticulationPoints(grid, newRow, newCol, discoveryTime,
                                           lowestReachable, parentCell, apInfo);

                    // Update lowest reachable time
                    lowestReachable[row][col] =
                        min(lowestReachable[row][col],
                            lowestReachable[newRow][newCol]);

                    // Check for articulation point condition
                    if (lowestReachable[newRow][newCol] >=
                            discoveryTime[row][col] &&
                        parentCell[row][col] != -1) {
                        apInfo.hasArticulationPoint = true;
                    }
                } else if (newRow * cols + newCol != parentCell[row][col]) {
                    // Update lowest reachable time for back edge
                    lowestReachable[row][col] =
                        min(lowestReachable[row][col],
                            discoveryTime[newRow][newCol]);
                }
            }
        }

        // Root of DFS tree is an articulation point if it has more than one
        // child
        if (parentCell[row][col] == -1 && children > 1) {
            apInfo.hasArticulationPoint = true;
        }
    }

    // Check if the given cell is a valid land cell
    bool isValidLandCell(const vector<vector<int>>& grid, int row, int col) {
        int rows = grid.size(), cols = grid[0].size();
        return row >= 0 && col >= 0 && row < rows && col < cols &&
               grid[row][col] == 1;
    }
};