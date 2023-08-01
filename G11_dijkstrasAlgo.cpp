/* o> Dijkstras Algorithm for Shortest path
 undirected graph with weighted path
 same as previous ; given a src node find least distance wala path
 DS required :
 distance wala toh chahiye hi - aur ek DS chiye jo darshaye minimum distance wali node konsi hai
 ek option hai priority queue ka use krna (minheap) ; ya ek set bhi le skte hai 

 ham set se karenge

 we need a set too 
 that will store pair of int , int ; first is for distance of node , and second is node 
 
 
*/

vector<int> dijkstra( vector<vector<int>> &vec, int vertices, int edges, int source){
    //create adjacecy list;
    unordered_map<int, list<pair<int, int>>> adj;
    for( int i = 0; i < vertices, i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(u,w));
        adj[v].push_back(make_pair(v,w));
    }

    //creation of ditance array with inf value initially
    vector<int> dist(vertices);
    for( int i = 0; i < vertices; i ++){
        dist[i] = INT_MAX;
    }

    // set <distance,node>
    set<pair<int,int>> st;

    //initialse distance and set with sourceNoed
    dist[source] = 0;
    st.insert(make_pair(0,source));

    while( !s.empty()){
        //fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top record
        st.erase(st.begin());

        //traverse on neighbours
        for( auto neighbour: adj[topNode]){
            if( nodeDistance + neighbour.second < dist[neighbour.first]){

                auto record = st.find(mak_pair(dist[neighbour.first],neighbour.first));
                //if record found then erase it 
                if( record != st.end()){
                    st.erase(record);
                }

                //distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                //record push in set
                st.insert( make_pair(dist[neighbour.first],neighbour.first))
            }
        }
    }
    return dist;
}
// TC O( E*logV )
// SC O( E + V )
