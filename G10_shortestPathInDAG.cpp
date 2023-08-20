/* 0> Shortest path in directed Acyclic Graph

 given a weighted graph
 src node se aur saare nodes tak ka shortest path ka weight batana hai
 the path chosen shld have lowest sum of weights
 
 approach
   topological sort nikalenge
   why? bcoz isse pta chal jayega which nodes lie before a node ... 
   aise linear ordering jisse ye pta chale ki khan se start kre or khan pahuche ye topo sort se pta chal jayega

   stack ki need hogi, visited ki hogi, adjList toh hona hi hai
   is bar adj list ka structure kuch different hoga as we need to include weights of edges too
   rather than unrodered_map<int, list< int>> 
   we would have unordered_map<int, list<pair<int,int>>> adj; // <startnode,listof<endnode,weight>>

   after finsing topo sort //  make a distance array initialised to inf
   set dist[src] = 0; // pehli node nikalenge agar inf hai dist array me toh ignore
   fir 1 pe aayenge toh uska toh 0 dist hi milega as it is the src node
   fir 2 pe jayenge toh 1 se 2 pe jaane ka jo weight hai wo update kardo in dist[2], 
   similarly 1 se jitne bhi adjacent node tak ja skte hai unke dist update karne hai
   fir pop krke from stack we go to next top in stack
   repeat the process of updating distances for this node's adjacent nodes too ( if only distance diff is smaller )
   

   distance jo hai usse update kr dunga
*/
void dfs(int node, vector<bool> &visited, stack<int> &st, 
            unordered_map<int, list<pair<int,int>>> adj){

   visited[node] = 1;

   for( auto neighbour : adj[node]){
      if(!visited[neighbour.first]){
         dfs(neighbour.first, visited, st, adj);
      }
   }

   st.push(node);
}

vector<int> shortestPathInDAG(unordered_map<int, list<pair<int,int>>> adj, int n, int src){

   vector<bool> visited(n, 0);
   stack<int> st;
   //topo sorting
   for( int i = 0; i < n; i++){
      if( !visited[i]){
         dfs(i, visited, st, adj)
      }
   }

   // declaring a distance vector and initialising to inf
   vector<int> dist(n);
   for( int i = 0; i < n; i++){
      dist[i] = INT_MAX;
   }

   dist[src] = 0;
   while( !st.empty()){
      int top = st.top();
      st.pop();

      if( dist[top] != INT_MAX){
         for( auto it : adj[top]){
            if( dist[top] + it.second < dist[it.first]){ // the logic
               dist[it.first] = dist[top] + it.second;
            }
         }
      }
   }

   return dist;
} // TC O(N + E) // SC O(N + E)