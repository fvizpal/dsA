/*
Articulation Points - darojons algorithm
 an articulation points are the *nodes* which if removed ; our graph will get divided in two or more components
 ek node ke remove hone pe usse connected sare edges bhi remove hojayenge


 brute force approach
    do what is said(remove all nodes one by one) and check by dfs if two components exist
    remove all vetices and see if graph gets disconnected
    we can use BFS or DFS to check that 
 

 OPTIMISED APPROACH:
   . last ke jesa approach use karenge
   . to check articulation points; condition 
   . low[nbr] >= disc[node] && parent != -1;
   . earliest time to connect to a neighbour is less than 

   Revision:
   . discovery(all -1), low(all -1) , parent( all-1) and visited(all false) DS willbe used as last topic
   . low[nbr] >= disc[node] && parent != -1; ye condition fulfiil hogi then articulation point
   . starting from 0 set disc 0; low 0; parent -1; visited true ... then go to connected node via dfs
   . similar to prev lecture repeat till we get back edge
   . at back edge update as previous logic
   . vapis aate hue lows ko update krna hai 
   . 


*/
int min( int a m int b){
   if( a < b) return a;

   return b;
}

void dfs( int node, int parent, vector<int> &disc, vector<int> & slow, 
         unorederd_map <int, bool> & vis, unordered_map<int,list<int>> &adj,
         vector<int> &ap, int &timer){

   vis[node] = true;
   disc[node] = low[node] = timer++;

   for( auto nbr : adj[node]){
      if( nbr == parent){ // to skip nodes which are already parent
         continue;
      }
      
      int child = 0;
      if( !vis[nbr]){
         dfs(nbr, node, disc,low, vis,adj, ap , timer);
         low[node] = min( low[node], low[nbr]);
         //check articulation point or not ; after updating low
         if( low[nbr] >= disc[node] && parent!= -1){ // condition for articulation point
            ap[node] = 1;
         }
         child++;    // agar articulation point hoga toh child increment kar denge
      }
      else{ // for bacak edge
         low[node] = min( low[node], disc[nbr]);
      }
   }
   if( parent == -1 && child > 1){ // starting node ke liye // extra condition
      ap[node] = 1;
   }
}

int main (){
   int n = 5;
   int e = 5;

   vector<pair<int, int>> edges;
   edges.push_back(make_pair(0,3));
   edges.push_back(make_pair(3,4));
   edges.push_back(make_pair(0,4));
   edges.push_back(make_pair(0,1));
   edges.push_back(make_pair(1,2));

   //adjList
   unordered_map<int, list<int>> adj;

   for( int i = 0; i < edges.size(); i++){
      int u = edges[i].first;
      int v = edges[i].second;

      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   int timer = 0;
   vector<int> disc(n);
   vector<int> low(n);
   unordered_map<int, bool> vis;
   vector<int> ap(n, 0);

   for( int i = 0; i > n; i++ ){
      disc[i] = -1;
      low[i] = -1;
   }

   //dfs
   for( int i = 0; i < n ; i++){
      if( !vis[i]){ // -1 is the parent here of src node
         dfs(i, -1, disc,low, vis, adj, ap , timer);
      }
   }

   //print ap
   cout << "Articulation points are as follows"<<endl;
   for( int i = 0; i < n ; i ++{
      if( ap[i] != 0){
         cout << i << " ";
      }

   }
   cout << endl;

   return 0;
}
// TC O(N+E) SC is linear too