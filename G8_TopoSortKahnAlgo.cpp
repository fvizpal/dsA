/* o> Topological sort using Kahn's algorithm  ... bfs USE KARENGE  
 sirf directed acyclic graph pe lag skta hai

 approach
    using Kahn's algorithm
    . indegree will be a DS that will store how many parent a node has
    . find indegree of all nodes
    . a queue and push nodes that have zero indegree into this
    . apply BFS  
        . front nikala fir pop kardiya
        . ans ke andar daal diya
        . neighbours nikalo aur neighbours ki indegree-- kardo 
        . jinki indegree zero ho jaye unhe queue me daaldo
        . nhi hui ho zero toh repeat the process
        . 
    
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
    vector<int> ans;
    while( !q.empty()){
        int front = q.front();
        q.pop();

        //ans store
        ans.push_back(front);

        //neighbour indegree update
        for( auto neighbour : adj[front]){
            indegree[neighbour]--;
            if( indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    return ans;
}
// TC is O( V + E)
// SC is O( V + E)