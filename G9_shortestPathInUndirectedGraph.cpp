/* 0> Shortest path in Undirected graph
 we will be given a src and destination 
 and we need to give shortest path between them
 (if all paths have same weight 1)
 BFS krte hua when we traverse ahead in a graph we are following the shortest ; that is the intuition for BFS

 approach
    . ham BFS ka prayog krenge 
    . ek aur DS chiye hoga to track parent othre than visited DS - queue ki need toh hai hi - BFS afterall
    . for src node mark it visited; set its parent as -1; take front node and pop
    . for each adjoint node( not visited ) mark visited and set parent ; then push into queue
    . repeat
    . issi parent ke track ko use krke we will get the ans
    . destination se parent se backtrack krke src tk pahuchenge 
 
*/

vector<int> shortestPath( vector<pair<int,int>> edges, int n , int m , int s , int t){ // s is src and t is target
    //create adjacency list
    unordered_map<int, list<int>> adj;
    for( int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //doing bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while( !q.empty()){
        int front = q.front();
        q.pop();

        for( auto i : adj[front]){
            if( !visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    //prepare shortest path
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while( currNode != s){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

//TC O(N + E) 
//SC O(N + E) // [considering adjacency list]

