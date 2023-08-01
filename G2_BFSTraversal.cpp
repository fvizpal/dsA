/* >Breadth First Search
 . sare neighbour values( ys kahe adjacent values ya connected values) pehle print hoti hai 
 . but haan pehle check hota pehle se printed ya stored ya visited toh nahi koi value
 

 ek visited ka track rkhna hoga // using an unordered map<node, bool> // initailly all are false that is not visited
 ek queue bhi chahiye usse first in first out ki func mil jayegi
 aur usse process karenge{
    . pehle frontnode queue ke ko le lete hain aur queue me se pop kar lete hn ( at very first it shall be the source node)
    . fir usse node ko visited mark kar dete hai
    . fir uski value ko print kar dete hai
    . fir uske saare adjacent queue me push kar dete hai( agar visited nahi hai toh )
    . repeat the process for now inserted nodes
 }
 
 // ek case aur ban skta hai ki jab disconnectd graph ho that is t2 componenets ko

*/

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int,int>> &edges){

    for( int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs( unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while( !q.empty()){
        int frontNode = q.front();
        q.pop();

        //store front node into ans
        ans.push_back(frontNode);

        //traverse all neighbours of frontNode
        for( auto it : adjList[frontNode]){
            if( !visited[it] ){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int,int>> edges){
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges); // this we need to make ourselves // as we are not given already

    //traverse all componenets of a graph // disconnected components ho skte hai
    for( int i = 0; i < vertex; i++){
        if( !visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

// HAME LIST KI JAGAH SET USE KRNE KI ZAROORAT PAD SKTI HAI 
// KYUKI SORTED MAI CHAHIYE 
// BAS SATH ME INSERT USE KAR LENA at place of push_back()

// agar disconnected components nahi hote toh simple call without for loop wld work
