/* o> Prims algorithm
 when we convert a graph into tree such that there are n nodes and n-1 edges
 and every node is reachable by every other node 
 ab aise spanning tree ho toh bhut saare skte hain but the minimum wld be the one with the 
 minimum cost of weights i.e. edges ke jo weight hai usse sum kare toh minimum hona chahiye


 we need three data structures to do so
 would be key, MST and parent, inke indexes nodes ko darsha rhe hai

 when at source that is the first element, make the key[0] = 0 too
 all others in key are inf for now
 and mark parent[0] = -1; 
 1.
    iske baad key value array me minimum value nikalenge 
    // to have the minimum weights requires for the problem
 2.
    now mark it in mst as true;
 3.
    abb sare adjacent laane hai ; unke parent update karne hai ;
    unke sath ye process repeat krna hai 
 after processing all the elements in this way // with the elements marked false only
 we will prepare our ans DS that will store the tree

*/
 
//                u to v    weight  // ye dikha rha hai ki konsa int kya dikha rha hai
vector<pair<pair<int, int>, int>> calculatePrimeMST( int n , int m, vector<pair<pair<int,int>, int>> &g){
    //creating adjacency list
    unordered_map<int, list<pair<int,int>>> adj;

    for( int i = 0; i < g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back( make_pair(v,w));
        adj[v].push_back( make_pair(u,w));
    }

    vector<int> key(n+1);  // node ko index se darsha rahe hai
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for( int i = 0; i <= n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    //starting the algo
    key[1] = 0;      // key is holding minimum weigths
    parent[1] = -1;  

    for( int i = 1; i < n; i++){ // yahan minimum find krne ke liye MIN HEAP ka use kar skte that will reduce time complexity here
        int mini = INT_MAX;
        int u;   // the store for minimum node
        //finding the min wali node
        for( int v = 1; v <= n; v++){
            if( mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }

        //mark min node as true
        mst[u] = true;

        //check its adjacent nodes
        for( auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if( mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int,int>,int>> result;     // 2 se isliye chala rhe kyuki 1 ka parent toh -1 hai
    for( int i = 2; i <= n; i++){              // ye result kese prepare kara jaa rha hai smjh nhi ayaa
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}
//TC is O(n^2);

// kya optimise kiya jaa skta hai 
// prority queue use kar skte hain // minHeap ka use krke minimum value O(n) me nikala jaa skta hai
// toh TC O(n*logn) ho jayegi
