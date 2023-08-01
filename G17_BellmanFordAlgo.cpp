/*
Bellman Ford Algorithm
 given DWG directed weighted graph
 negative weight bhi use ho skti hai 

 par ham Dijkstras toh kar chuke hai ;; nhi ham usme nigative ke liye nih kar skte hain 
 negative weights ke case me ye wrong answer dega

 bas haan negative cycle nhi honi chahiye 

 what it says is that we will have to apply below formula n-1 times
    if( dist[u] + wt < dist[v]){
        dist[v] = dist[u];
    }
  
 sari edges pe karna he ye formula n-1 times apply

 one more time same formula apply karo 
 agar koi distance update ho jaye toh negative cycle present hai or aap negative cycle nahi nikal skte 
 
 1 - 2
 1 - 3
 2 - 3
 example graph ke edges hain

*/
int bellmanFord( int n, int src, int dest, vector<vector<int>> &edges){

    vector<int> dist(n+1, 1e9);
    dist[src] = 0;

    for( int i = 0; i <= n; i++){
        //traverse on edge list 
        for( int j = 0; i < m ; j++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            if( dist[u] != 1e9 && ((dist[u] + wt) < dist[v] )){
                dist[v] = dist[u] + wt;
            }
        }
    }

    //check for negative cycle 
    bool flag = 0;
    for( int j = 0; j < m; j++){
        int u = egdes[j][0]
        int v = egdes[j][1]
        int wt = egdes[j][2]

        if( dist[u] != 1e9 && ((dist[u] + wt) < dist[v] )) {
            flag = 1;
        }
    }

    // upar ki checking for negaive cycle hata de aur sirf return dist[dest] karde // fir bhi ye code same chalega if it is given in the question that there is no negative cycle

    if( flag == 0){
        return dist[dest];
    }
    return -1;
}
// TC is O(n*E)

