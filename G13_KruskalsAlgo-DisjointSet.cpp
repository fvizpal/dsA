/* o> Kruskals Algorithm - Disjoint set
  Pre Req hai ki DISJOINT SET smjhna hoga
  it is a type of DS ( cycle detect bhi isse ho jata hai)
  if in a graph there are multiple components; then if we want to know if two nodes belong to same or
  different component   for this too Disjoint set can be used

  TWO MAJOR operations in this
  1. find parent or find set
  2. Union() or union Set()

  jab union karte hai do components (a,b) ka toh ek component ban jata hai with all nodes of components a,b
  Union by rank and path compression se iski implementaion kar skte hai
  
  ek rank ka array banaenge // or starting sabke rank 0 honge
  jindo ka nodes ka union krna hai pehle uske parent dekhenge( sabse grand waale) fir unki(parent ki) rank dekhenge
  agar dono ki rank same hai toh kisiko kisike sath bhi attach kar skte hai as parent and child

  if rank of a is smaller than rank of b ; then b will be parent of a
  and vice versa
  sath hi rank ko increment karenge of the node which has became parent

  agar path aise hai ki 7--> 6--> 4 toh 
  sidhe 7 ko 4 se lagao 7--> 4
  this is path compression

  agar check karna hai if two nodes lie in same component then check if there parent are same
  if are; then same componenet; else not

  KRUSKAL'S ALGO
    adjList ki zaroorat nhi hai 
    linear DS ki hai usme wt aur u & v  store krenge // u & v are node values

*/

//Minimum spanning tree

//-------initialisation
void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for( int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

//-----------to find parent
void findParent(vector<int> &parent, int node) {
    if( parent[node] == node){ // jab khud ka hi parent aa jaye toh ruk jaana hai // heirarchy me oopar jarhe hai
        return node;
    }

    // here we are eleminating the intermediate nodes between the node and parent
    return parent[node] = findParent(parent, parent[node]); // yha path compression hogya
}

//----------------jin 2 ka union
void unionSet( int u , int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);  // parent nikalaenge pehle
    v = findParent(parent, v);  // dono ke

    if( rank[u] < rank[v]){  // less vale ka parent change krenge
        parent[u] = v;
    }

    else if( rank[v] < rank[u]){  // less vale ka parent change
        parent[v] = u;
    }
    
    else{           // equal rank // you can make any one as node and the other as child
        parent[v] = u; // make sure to increment rank
        rank[u]++;  // jisko parent banaenge uski rank incremented
    }
}
//--------------ye vo linear DS hai
// ----------------------- end of union rank function

// ------------- KRUSKAL's ALGORITHM
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}
int minimumSpanningTree( vector<vector<int>> &edges, int n) {
    
    // no need of adjacency list

    sort(edges.begin(), edges.end(), cmp);  // sabse pehle sort karenge // wt ke basis pe 

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet( parent, rank, n);  // initialse krne k liye func 
    // initially every node is parent of itself
    // and rank of every node is zero

    int minWeight = 0;

    for( int i = 0; i < edges.size(); i++){
        int u = findParent(parent, edges[i][0]); // dono nodes ke liye parent find karenge
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if( u != v){    //different component ke hai toh merge krna hai i.e. union
            minWeight += wt;   // merge jinko krenge unke wts add kar diye
            unionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}
// TC is O( m * logm )
// find parent function ka TC nearly constant hota hai
// similarly of union