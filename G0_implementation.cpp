#include<bits/stdc++.h>
using namespace std;
#include<list>
template <typename T>

class Graph{
    public:
    unordered_map<T, list<T> > adj;
    void addEdge( T u, T v, bool direction){
        //direction = 0 : undirected graph
        //direction = 1 : directed graph

        //creating an edge from u to v
        adj[u].push_back(v);
        if ( !direction ){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for ( auto i : adj){
            cout << i.first << " -> ";
            for( auto: i.second){
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};

// printing connections to a node
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int >> &edges){
    vector<int> ans[n];
    // ans will store all adjacent nodes corresponding to indices

    for( int i = 0; i< m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for( int i = 0; i< n; i++){
        adj[i].push_back(i);

        //entering neighbours
        for( int j = 0; j < ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }

    return adj;
}

 // TC ans SC are HW

int main (){
    int n;
    cout << "Enter no of nodes : ";
    cin >> n;
    int m;
    cout << "Enter no of edges : ";
    cin >> m;

    Graph<int> g; // you can specify the tyoe if data in the graph

    for( int i = 0 ; i < m; i++){
        int u, v;
        cin >> u >> v;
        addEdge(u, v, 0);
    }

    g.printAdjList();

    return 0;
}