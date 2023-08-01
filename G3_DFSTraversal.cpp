/* o> Depth First Search traversal
 isme saare adjacent nods ko nhi balki haar node pe uske aur depth me jaate hai
 recursion karte hai 
 ek visited check karne ke liye DS use krenge preferably map
 
 adjacency list aban lo pehle

 lets say we start from a source node 
 . usko pehle visited me true mark kar do
 . fir uske ek connected node( ek depth) me jao
 . usko bhi true mark kardo
 . fir uske connected ( agar  visited nahi hai (isliye source node pe vapis nahi jayega))
 . unpe jao or true mark kardo - btw ye jana recursion se ho rha hai
 . keep doing utill no node is left that is not previously visted

 // disconnected graph bhi honge unke liye for loop
*/
void dfs( int node, unordered_map<int, bool> &visited, 
            unordered_map< int, list<int>> &adj, vector<int> &component){
    
    // storing in ans
    component.push_back(node);
    //marking it visited
    visited[node] = true;

    // har connected node ke liye recursive call
    for( auto i : adj[node]){
        if(!visited[i]){
            dfs( i , visited, adj, component);
        }
    }
}

vector<vector<int>> DFSearch(int V, int E, vector<vector<int>> &edges){
    //prepare adjList
    unordered_map< int , list<int>> adj;
    for( int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);  // kyuki undirected hai
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    //for all nodes calling dfs if not visited
    for( int i = 0; i < V; i++){
        if(!visited[i]){        // agar visited nahi hai toh dfs call kar rhe hai
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }

    return ans;
}
// TC and SC is O( n ) 