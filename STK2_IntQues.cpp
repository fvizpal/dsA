/* 0 
ek array ke andar do stacks inplement kiya tha 


*/



/* 1
Reverse a string using stack
 
 isse pehle ye same hamne 2 pointers and swapping se kiya tha
 now using stack; LIFO toh iski property hai hi
    

*/

string reverse( string str){
    stack<char> s;

    for( int i = 0; i < str.length(); i++){
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while( !s.empty()){
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }

    return ans ;

}

/* 2
Delete middle element from stack
 size toh stack ka pta chal hi jayega 
 size / 2 depth tak jayenge stack me 


*/

void solve(stack<int> &inputStack, int cnt, int n){
    // base case
    if( cnt == n / 2){
        inputStack.pop();
        return;

    }
    int num = inputstack.top();
    inputStack.pop();

    //recursive call
    solve( inputStack, cnt + 1,size);

    inputStack.push( num);
}

void delteMiddle( stack<int> &inputStack, int n){

    int cnt = 0;
    solve( inputStack, cnt, n);
}

/* 3
Valid parenthesis
 har ek opening bracket ka order me coreesponding closing bracket hona chahiye

 Stack use krenge
 
*/
bool isValidParenthesis(string expression){

    stack<char> s;
    for( int i = 0; i < expression.length(); i++){

        char ch = expression[i];

        //if opening bracket, push into stack
        //if closing bracket , check stack top and pop

        if( ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else {
            // for closing bracket
            if( !s.empty()){
                char top = s.top();
                if( ( ch == ')' && top == '(') ||
                    ( ch == '}' && top == '{') ||
                    ( ch == ']' && top == '[') ) {
                    s.pop();
                }
                else {
                    return false;
                }
            } 
            else {
                return false;
            }
        }

    }
    if( !s.empty())
        return true;
    else    return flase;
}

/* 4
Insert an element at bottom of stack
 har bar elleement pop karo and check ki stack empty hai ki nhi 
 jab ho jaye toh push krdo desired element 
 and then put all elements back


*/
void solve( stack<int> &s, int x){
    //base case
    if( s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    solve( s , x);

    s.push( num);
}

stack<int> pushAtBottom( stack <int> &myStack, int x){

    solve( myStack, x);
    return myStack;
}

/* 5
Reverse stack using recursion
 
*/

void insertAtBottom( stack<int> s,int element){
    if( s.empty()){
        s.push( element);
        return;
    }
    int num = s.top();
    s.pop();

    //recursive call
    insertAtBottom( s, element);

    s.push(num);
}

void reverseStack( stack<int> &stack){
    //base case
    if( stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    //recursive call
    reverseStack( stack);

    insertAtBottom( stack, num);

} 
// TC is  O( n^2)

/* 6
Sort a stack
 no using of loop

*/

void sortedInsert( stack<int> & stack, int num){
    //base case
    if( stack.empty() || (!stack.empty() && stack.top() < num)){
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    //recursive call
    sortedInsert(stack, num);

    stack.push(n);
}

void sortStack( stack<int> &stack){
    //base case
    if( stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    // recursive call
    sortStack( stack);

    sortedInsert( stack, num);
}

/* 7
Redundant Brackets
 pair of brackets are redundatn when its use is useless
 

 approach(
    a loop jo har bar ek ch uthayega 
    agar vo ch kisi prakar ka operator hai ya open bracket hai toh isse ek stack me daal denge
    else agar closing bracket h ya english letter hai toh 
 )
*/

bool findRedundantBrackets( string &s){

    stack<char> st;
    for( int i = 0; i < s.length(); i++){
        char ch = s[i];

        if( ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }

        else {
            // ch ya toh closing bracket hai ya letter hai 
            if( ch == ')'){
                bool isRedundant = true
                while( s.top() != '('){
                    char top = st.top();
                    if( top == '+' || top == '-' || top == '*' || top == '/' ){
                        isRedundant = false;
                    }
                    st.pop();
                }   
                if( isRedundant){
                    return true;
                }
                st.pop();
            }
        }
    }

    return false;
}

/* 8
Minimum cost to make string valid 
 every closed brace should have closed brace before it 
 toh me kitne braces ko invert krdu ki expression valid ban jaye 

 approach{
    odd ke case me -1 return krna hai 
    input string se valid part ko remove krdo 
    remaining part sare open honge ya sare close honge ya kuch open pehle aur uske bad closed 7 vice versa honge
    
 }
*/




/* 9
Next smaller element 
 for every element we want to find the first smaller window in the eindow ahead of that element
 
 approach {
    starting me stack me -1 store kar lena 
    fir compare krenge the smallest element till now 

 }
*/

vector<int> nextSmallerElement( vector<int> &arr , int n ){
    stack<int> s;
    s.push( -1);
    vector<int> ans(n);

    for( int i = n-1; i >= 0; i--){
        int curr = arr[i];
        while( s.top() >= curr){
            s.pop();
        }

        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
} // TC is O(n)  //  



/* 10
Largest rectangular area in a histogram

    pehele brute force se hi dekhenge har rectangle pe serial wise jaake puchenge if it can be extended to left or right
    and by how much ;; sare area nikal ke max dekh lenge
    TC wld be O(n^2)

    NOt good enough

    O(n) me krna hai
    stack ka use krenge pichle question ke concept ka use bhi use krenge
    
*/
vector<int> nextSmallerElement( vector<int> &arr , int n ){
    stack<int> s;
    s.push( -1);
    vector<int> ans(n);

    for( int i = n-1; i >= 0; i--){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }

        //ans is stack ka top
        ans[i] = s.top();
        s.push(i); // index or vector k lliye modify kiya hai 
    }

    return ans;
}

vector<int> prevSmallerElement( vector<int> &arr , int n ){
    stack<int> s;
    s.push( -1);
    vector<int> ans(n);

    for( int i = 0; i < n; i++){
        int curr = arr[i];
        while( s.top() >= curr){
            s.pop();
        }

        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

int largestRectangle( vector<int> &heights){

    int n = heights.sixe();

    vector<int> next(n);
    next = nextSmallerElement( heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement( heights, n);

    int area = INT_MIN;

    for( int i = 0; i < n; i++){
        int l = heights[i];

        if( next[i] == -1)      next[i] = n; // ye jaroori hai nhi toh wwodth -1 aa jayegi

        int b = next[i] - prev[i] - 1;

        int newArea = l*b;
        area = max(area, newArea);
    }

    return area;
}
// yr hai TC O(n) me
