/* o> Bridges in a graph
  Bridge ek aisi edge hoti hai jisko remove kaarne se no. of connected components increase kar jayenge
 
 brute force approach
    har edge ko pakodo aur remove karke check karo; now check using dfs how many components; if no. of connecctes neighbours == 0;
    by DFS
 
 // but we shall have an optimised approach

 optimised approach:
    . we require some DSs ; 4 to be precise; disc, low, parent, visited ; all are vectors
    . starting me 0 se start krenge so disc[0] = 0, low[0] = 0; timer incremented; mark 0 as visited and parent as -1
    . now moved to node 1; disc as 1 and timer wld be incremented by 1; low set to 1; vsited marked; parent set to 0;
    . now node 2; now discovery time for 2 is 2; loq is set to 2; mark visited and parent as 1;
    . now again 0 pe jrhe hai as per the edge so it is a back edge; iska matlab 2 tak jaane ka ek lower time bhi hai
    . viz. directly from 0 to 2 so now low shld beupdated; low[node] = min(low[node], disc[nbr])
    . ek or tareeka hai 2 se 1 tk bhi toh? nahi ! parent or nbr same ho toh ignore krna hai
    . to check if that edge is bridge if low[nbr] > disc[node] then its a bridge // kyuki iska maatlab hai ki
    . vha tak phuchne ka ye iklauta tareeka hai so ; it has to be bridge
    . now 0 se 3 jrhe hai and repeat

 4 DS banenge 1. Discovery 2. Low 3. parent 4. visited
*/

void dfs( int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
            vector<vector<int>> &result, unordered_map<int, list<int>> &adj,
            unordered_map<int,bool> &vis){

    vis[node] = true;
    disc[node] = low[node] = timer++;

    for( auto nbr : adj[node]){
        if( nbr == parent){
            continue;
        }
        if( !vis[nbr]){
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);  // jab call se vapis aate hai
            //check edge is bridge
            if( low[nbr] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            // node already visited and not parent
            // i.e. back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges( vector<vector<int>> &edges, int v, int e){

    //adjList
    unordered_map<int, list<int>> adj;
    for( int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> vis;

    for( int i = 0; i < v; i++){
        disc[i] = -1;
        low[i] = -1;
    } //initialise

    vector<vector<int>> result;
    //dfs
    for( int i = 0; i < v; i++){
        if( !vis[i]){
            dfs( i, parent, timer, disc, low, result, adj, vis);
        }
    }

    return result;
}
//TC is O( V + E);
//SC is O( N );