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

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
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

    while( !st.empty()){
        //fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top record
        st.erase(st.begin());

        //traverse on neighbours
        for( auto neighbour: adj[topNode]){
            if( nodeDistance + neighbour.second < dist[neighbour.first]){

                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
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

// ----------WITH PQ
void Graph::shortestPath(int src) {
    // Create a priority queue to store vertices being processed
    // Priority queue sorted by the first element of the pair (distance)
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // Create a vector to store distances and initialize all distances as INF
    vector<int> dist(V, INF);

    // Insert source into priority queue and initialize its distance as 0
    pq.push(make_pair(0, src));
    dist[src] = 0;

    // Process the priority queue
    while (!pq.empty()) {
        // Get the vertex with the minimum distance
        int u = pq.top().second;
        pq.pop();

        // Iterate through all adjacent vertices of the current vertex
        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If a shorter path to v is found
            if (dist[v] > dist[u] + weight) {
                // Update distance and push new distance to the priority queue
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print the shortest distances
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
        cout << i << " \t\t " << dist[i] << endl;
}
