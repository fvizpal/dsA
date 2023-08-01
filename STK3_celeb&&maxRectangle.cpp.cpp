/* 1
Celebrity Problem
 every one knows the celebrity
 but celeb knows no one
 aapko btana hai who is celebrity among n people

 input me 2D matrix de rkhi hai ki kya col[i] row[i] ko janta hai 
 and this is true or false by either value 1 or 0 in the matrix
 obviously diagnol element saare 0 honge kyuki khud ko toh jante hi honge
 
 approach{
    
    jo celeb wali row hai vo sari zero hogi
    in celeb column all except diagnol are 1

    1 brute force 
    O(n^2) wld be its TC

    2 using stack
        ek stack bnao ; stack me at last celeb element hi bachega
        at start sare element daal do in stack
        jab tak stack ka size 1 nhi hai tbtk
        2 elements nikaal lo top ke A and B
        if( A knows B) a ko discard kardo aur B ko firse daal do
        else B ko discard and A ko vappis daaldo
        jo single element bcha hua hai vo POTENTIAL celeb hai
        verify krne k liye uske rows 0 honi chiye and col except diagnol 1 honi chiye
 }

*/

int celebrity( vector<vector<int>> &M, int n ){
    stack<int> s;
    // 1: push all elements in stack

    for( int i = 0; i < n ; i++){
        s.push(i);
    }

    //2:
    while(s.size() > 1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if( M[a][b] == 1){
            s.push(b);
        }
        else{
            s.push(a);
        }

    }

    int candidate = s.top();

    //step3: single element in stack is potential celeb
    // so verifying it 
    bool rowCheck = false;
    int zeroCnt = 0;
    for( int i = 0; i < n; i++){
        of( M[candidate][i] == 0){
            zeroCnt++;
        }
    }

    //all zeroes
    if( zeorCnt == n){
        rowCheck = true;
    }

    //column check
    bool colCheck = false;
    int colCnt = 0;

    for( int i = 0; i < n ; i++){
        if( M[i][cnadidate] ==1){
            colCnt++;
        }
    }

    if( colCnt == n-1){
        colCheck = -1;
    }

    if( rowCheck == true && colCheck = true){
        return candidate;
    }
    else {
        return -1;
    }
}
// iske bahut solutions hain // aur optimise kari jaa skti hai
// toh dekhiye



/* 2
Max Rectangle in Binary matrix with all 1's
 har ek row ko base maanke histogram jesa hi bnaenge ( see note book)
 
 // extensive use of max rectanlge in histogram wala concept

*/

vector<int> nextsmall(vector<int>& arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=arr.size()-1;i>=0;i--){
        
        while(s.top()!=-1&&arr[s.top()]>=arr[i])
        s.pop();
        if(s.empty()){
        ans[i]=arr[i];
        s.push(arr[i]);
        }
        else
        {
        ans[i]=s.top();
        s.push(i);
        
        }
        
    }
    return ans;
}
vector<int> prevsmall(vector<int>& arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        
        while(s.top()!=-1&&arr[s.top()]>=arr[i])
        s.pop();
        if(s.empty()){
        ans[i]=arr[i];
        s.push(arr[i]);
        }
        else
        {
        ans[i]=s.top();
        s.push(i);
        
        }
        
    }
    return and;
}
int largestRectangleArea(vector<int>& heights) {
    int area=0;
    int n =heights.size();
    vector<int> next(n);
    vector<int> prev(n);
    next=nextsmall(heights,n);
    prev=prevsmall(heights,n);
    for(int i=0;i<n;i++){
        int l=heights[i];
        if(next[i]==-1)
        next[i]=n;
        int b=next[i]-prev[i]-1;
        int newarea=l*b;
        area=max(newarea,area);
    }
    return area;
}

int maxArea( int M[MAX][MAX], int n, int m ){

    //compute area of first row
    int area = largestRectangleArea(M[0], m);

    for( int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){

            //row update: by adding previous row's value
            if( M[i][j] != 0)
                M[i][j] = M[i][j] + M[i-1][j];
            else 
                m[i][j] = 0;
        }

        //entire row is updated now
        area = max( area, largestRectangleArea( M[i], m));
    }

    return area;
}
TC wld be O(n*m) ;
SC wld be O(m) ;  //  number of columns 