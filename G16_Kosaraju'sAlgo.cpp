/*
Kosarajus Algorithm
 used to find strongly connected components 
 a component which is such that regardless of where we start ; we can traverse whole of component

 cNinja: https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbGswWGczc2JIN3BuVlo3a29zdUVUczU2OEQ5Z3xBQ3Jtc0tudmhaNGhnREI2RDVVOXV4emdJUV9BdEZwTnVIdHpLdDRLbl9tNjcxS2Q5U3Q0aXdoT2RjTDRTeFlnaWg2a2FTOUF2ZGtRek00dDRyZ1Rkd2hEdU5rbVlPTlBfZnpHRXdOS2s3WUh5T2JYSGxxbUlnaw&q=https%3A%2F%2Fwww.codingninjas.com%2Fcodestudio%2Fproblems%2Fcount-strongly-connected-components-kosaraju-s-algorithm_1171151%3FleftPanelTab%3D0%26utm_source%3Dyoutube%26utm_medium%3Daffiliate%26utm_campaign%3DLovebabbar&v=ndfjV_yHpgQ
 
 algo[ // kehti hai ki 
    1 sort all nodes on basis of their finishing time 
    2. transpose graph
    3. dfs apply krke count of components nikalenge

 ]

*/

void dfs( int node, unoredere_map<int, bool> &vis,
            stack<int> &st, unorederd_map<int, list<int>> &adj){

                vis[node] = true;
                for( auto nbr : adj[node]){
                    if( !vis[nbr]){
                        dfs( nbr, vis, st, adj);
                    }
                }
                // topo logic
                st.push(node);
}

void revDfs( int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj){

    vis[node] = true;

    for( auto nbr:adj[node]){
        if( !vis[nbr]){
            revDfs(nbr,vis, adj);
        }
    }

}

int stronglyConnectedComponents( int v, vector< vector<int>> & edges ){
    //adj
    unordered_map<int, list<int>> adj;
    for( int i= 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //topo sort
    stack<int> st;
    unordered_map<int, bool> vis;
    for( int i = 0; i < v; i++){
        if( !vis[i]){
            dfs( i, vis, st, adj);
        }
    }

    //create a transpose graph 
    unordered_map<int, lisr<int>> transpose;
    for( int i = 0 ; i < v; i++){
        for( auto nbr:adj[i]){
            transpose[nbr].push_back(i);
        }
    }

    //dfs call using above ordering 
    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if( !vis[top]){
            count++;
            revDfs( top, vis, transpose);
        }
    }

    return count;
} // TC is O( N + E) // SC is linear as well

