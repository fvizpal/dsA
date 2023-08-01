/* o> Topological sort using DFS
 can be applied only to DAG ( directed acyclic graphs )
 see notebook to understand what it is;

 starting from the source node we need to linearly order all vertices in direction of the DAG
 that is if  3--> 2 then in the output we shall have 3 before 2
 if a node directs to two or more nodes then those nodes can be printed in any order
 i.e 3-->2 & 3-->1 then 1 & 2 come after 3 but 2 and 1 not strictly have to be one after another; 3 2 1 and 3 1 2 are both valid
 but what comes before and after in this ambiguity may depend on adjList

 Topo sort cycle ke case me nhi kaam  kar payega

 approach
    using DFS
    . ek additional DS ki zaroorat hogi - and that will be a stack(LIFO) besides visited DS
    . dfs traverse krte jayenge
    . when ever returning from the dfs function call for a node ; push that node into the stack
    . now the stack from top to bottom shall have our topo sort
    . TC O(V+E)  // SC O(V)
*/

void topoSortDFS( int node, vector<bool> &visited,stack<int> &st,unordered_map<int, list<int>> adj ){
    visited[node] = 1; 

    for( auto neighbour : adj[node]){
        if( !visited[neighbour]){
            topoSortDFS(neighbour,visited,st,adj);
        }
    }
    //imp
    st.push(node);
}

vector<int> DFSTopologicalSort(vectot<vector<int>> &edges, int v, int e ){
    unordered_map<int, list<int>> adj; // iski jagah bhi vector<vector<int>> use krke time kam kr skte hn
    // creating an adj list
    for( int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        // since directed
    }

    // call dfs topological sort util function for all component
    vector<bool> visited(v);
    stack<int> st;
    for( int i = 0; i < v; i++){
        if( !visited[i]){
            topoSortDFS(i, visited, st, adj);
        }
    }

    vector<int> ans;
    while( !st.empty()){
        ans.push_back(st.top());
    }
    
    return ans;
}   