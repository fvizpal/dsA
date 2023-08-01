/*
if lets say any node is ignited 
what wld be the minimum time for complete tree to turn onto ash

it takes 1 sec to burn all adjacent nodes of a node
or ham kisi bhi node ko ignite kr skte hn 

toh un sabhi posibilities me minimum time kiska hoga

1:
    left or right toh thik h par parent ko kese burn krenge since it will also be a neighbour node
    toh ham har node ki ek uske parent ke sath mapping rkhenge 
    LOT se kr skte hn
2:
    pr pehle ignited node tak phuchna h toh
    find that target node iski O(h) ho jayegi

3:
    abb burn krna start krenge
    koi node visited h ki nhi ye bhi ek map se dekhnge
4:

*/

Node* createParentMapping( Node* root , int target, map < Node* , Node* > &nodeToParent){
    Node* res = NULL;

    queue<Node*> q;
    q.push( root);
    nodeToParent[root] = NULL;

    while( !q.empty() ){

        Node* front = q.front();
        q.pop();

        if( front -> data == target){
            res = front;
        }

        if( front->left){
            nodeToParent[front->left] = front;
            q.push(front -> left);

        }
        if( front ->right){
            nodeToParent[front -> right] = front;
            q.push(front->right);
        }
    }

    return res;

}
int burnTree(Node* root, map< Node*. Node* > &nodeToParent){

    map<Node* , bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while(!q.empty()){
        bool flag = 0;

        int size = q.size();
        for( int i = 0; i < size; i++){
            //processing the neighbouring nodes
            Node* front = q.front();
            q.pop();

            if( front ->left && !visited[front->left]){
                flag = true;
                q.push(front->left);
                visited[front->left] = 1;
            }

            if( front -> right && !visited[front->right]){
                flag = true;
                q.push(front->right);
                visited[front->right] =1;
            }
            if( nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodetoParent[front]] = 1;
            }
        }
        if( flag){
            ans++;
        }
    }
    return ans;

}

int minTimeToBurn(){

    // int ans = 0;
    map<Node*,Node*> nodeToParent;
    Node* targetNode = createParentMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodetoParent);

    return ans;
} // TC is O(n*logn)  &  SC is O(n)
