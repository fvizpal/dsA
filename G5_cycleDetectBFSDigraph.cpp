/* o> Detect cycle in a Directed graph using BFS 
 we ll be taking help of inverse of TOPOLOGICAL SORT 
 using KAHN's algo 
 that is agar valid topo sort hai toh DAG hoga // that is acyclic

 *Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering
   of vertices such that for every directed edge u v, vertex u comes
    before v in the ordering.
 
 // in a valid topo sort total nodes in the output wld be equal to number of nodes in graph
 // so we will check if the cnt is equal to number of nodes ; if equal then ACYCLIC else CYCLIC
 cnt == v ? return false : return true;
*/

vector<int> topologicalSort( int v , int e, vector<vector<int>> &edges){
    //creating adj List
    unordered_map<int,list<int>> adj;
    for( int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //find all in  degree
    vector<int> indegree(v);
    for( auto i : adj){
        for( auto j : i.second){
            indegree[j]++;
        }
    }

    // 0 indegree waalo ko push krna hai 
    queue<int> q;
    for( int i = 0; i < v; i++){
        if( indegree[i] == 0){
            q.push(i);
        }
    }

    //do bfs
    // vector<int> ans;
    int cnt = 0;
    while( !q.empty()){
        int front = q.front();
        q.pop();

        //ans store
        // ans.push_back(front);
        cnt++;

        //neighbour indegree update
        for( auto neighbour : adj[front]){
            indegree[neighbour]--;
            if( indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    // in a valid topo sort total nodes in the output sort wld be equal to number of nodes in graph
    // so we will check if the cnt is equal to number of nodes ; if equal then ACYCLIC else CYCLIC
    cnt == v ? return false : return true;
    
}