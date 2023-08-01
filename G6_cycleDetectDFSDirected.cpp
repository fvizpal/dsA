/* o> Detecting cycle in DIGRAPHS
 we will do this with DFS
 but same undirected wala logic nhi lga skte
 ki agar visited ho aur parent na ho; toh true; ye kaam nhi krega ; try dry running

 is bar normal visited nhi krenge ;; this will be dfs visited which will get true on a forward dfs call
 jab function call se vapis jaarhe ho toh dfsVisted false kar dena hai
    if visited && dfsVisited tab cycle present hai
*/

bool checkCycleDFS( int node, unordered_map<int, bool> &visited; 
            unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adj){

    visited[node] = true;
    dfsVisted[node] = true;

    for( auto neighbour : adj[node]){
        if( !visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
            if( cycleDetected)  return true;
        }
        else if( dfsVisited[neighbour]){
            //visited true && dfsVisited true
            return true;
        }
    }

    dfsVisited[node] = false; // vapis jaane se pehle dfs visited false kar dena hai
    
    return false;
}

bool detectCycleInDirectedGraph( int n, vector< pair<int, int>> &edges){
    //creating adj list
    unordered_map<int, list<int>> adj;
    for( int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    //call dfs for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;
    for( int i = 1; i <= n; i++){
        if( !visited[i]){
            bool cycleFound = checkCycleDFS( i, visited, dfsVisted, adj);
            if( cycleFound)     return true;
        }
    }

    return false;
}
// TC O( V + E) // SC is linear too
