/*
  Find shortest distance in an weighted graph between all pairs of vertices

  Dijktra ? Can be used but it will have O(n^2) complexity and for every node
    this becomes O(n^3);
  Dijkstra's algorithm does not work correctly with graphs that have negative 
  edge weights. The Floyd-Warshall algorithm can handle graphs with both positive 
  and negative edge weights.

  we'll utilise DP 
  - we find out if the shortest path comprises the shortest path of some intermediate
    vertex
  
  In adjacency matrix - no edge is marked with inf
    for self edge the value is put 0
  
  Floyd Warshall Algorithm:
  - Initialize the solution matrix same as the input graph matrix
  - Then update the solution matrix by considering all vertices as an intermediate vertex. 
  - The idea is to pick all vertices one by one and updates all shortest paths 
    which include | the picked vertex as an intermediate vertex | in the shortest path. 
  - When we pick vertex number k as an intermediate vertex, we already have 
    considered vertices 0, 1, 2, .. k-1 as intermediate vertices. 
  - Every succesive matrix is calculated using the previous matrix
  - For every pair (i, j) of the source and destination vertices respectively, 
    there are two possible cases. 
    - k is not an intermediate vertex in shortest path from i to j. 
      We keep the value of dist[i][j] as it is. 
    - k is an intermediate vertex in shortest path from i to j. We update the 
      value of dist[i][j] as dist[i][k] + dist[k][j], if dist[i][j] > dist[i][k] + dist[k][j]
*/


// Will return a matrix with shortest path between vertice i and j at mat(i, j);
vector<vector<int>> findShrotestPathBetweenAllPairsOfVertices(
  vector<vector<int>> edges,
  int n
) {

  // preparing adjacency matrix
  vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
  for(auto edge : edges) {
    int u = edge[0];
    int v = edge[1];
    int wt = edges[2];

    adj[u][v] = wt;
  }

  // self edges have zero weight;
  for(int i = 0; i < n; i++) {
    adj[i][i] = 0
  }

  vector<vector<int>> res = adj;

  for(k = 0; k < n; k++) {
    // Pick all vertices as source one by one
    for(i = 0; i < n; i++) {
      // Pick all vertices as destination for the
      // above picked source
      for(j = 0; j < n; j++) {
        // If vertex k is on the shortest path from
        // i to j, then update the value of
        // dist[i][j]
        if(dist[i][j] > (dist[i][k] + dist[k][j])
          && (dist[k][j] != INT_MAX
          && dist[i][k] != INT_MAX)
        )
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  return res;
} // TC O(n^3)

int main () {


  return 0;
}