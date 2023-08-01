/* o> CYCLE detection in undirected graph
 
 we will be using BFS and DFS traversal here

 parent track krne k liye ek aur data structure banaenge
 . jab parent ho && visted ho toh uss node ko queue me mat daalo // neglect kar do
 . jab visited true ho && vo uska parent na ho ; we've got a cycle buddy

*/

// using BFS traversal
bool isCycleBFS(int src, unordered_map<int,bool> &visited, unordered_map<int, list<int>> & adj){
    
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while( !q.empty()){
        int front = q.front();
        q.pop();

        for( auto neighbour: adj[front]){
            if( visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }
            else if ( !visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}


// THIS IS USING DFS 
bool isCycleDFS(int node, int parent, unordered_map<int, bool> &visited, 
                    unordered_map<int, lsit<int>> &adj){
    
    visited[node] = true;

    for( auto neighbour : adj[node]){
        if( !visited[neighbour]){
            bool isCycleDetected = isCycleDFS(neighbour, node, visited, adj);
            if( isCycleDetected )
                return true;

        } else if( neighbour != parent){ // visited hai && parent nahi hai; toh cycle-true;
            //cycle present
            return true;
        }
    }
    return false;
}

bool cycleDetection( vector<vector<int>> &edges, int n, int m){
    //creating adjacency list
    unordered_map<int, list<int>> adj;
    for( int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //to handle disconnected components
    unordered_map<int, bool> visited;
    for( int i = 0; i < n; i++){
        if( !visited[i]){
            bool ans = isCycleBFS( i, visited, adj);
            // bool ans = isCycleDFS(i, -1, visited, adj)
        }
    }
    return ans;
} // TC is still linear // similar to that of traversal

// DFS se bhi kar skte hain
// agar aap DFS krte hue aisi node p pahuch jaye jiska node pehle se visited hai
// toh cycle hai
