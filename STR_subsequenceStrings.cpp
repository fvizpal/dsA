

// function solve       ----       ensure pass by reference
void solve( string str, string output, int index, vector<string>& ans){
    //base case
    if ( index >= str.lemgth()){
        if(output.lenght() > 0){  // top not include the empty string
            ans.push_back(output);          
        }
        return;
    }

    //exclude;
    solve( str, output, index + 1, ans );

    //include;
    char element = str[index];
    output.push_back(element);
    solve( str, output, index, ans);
    return ans;
}

vector<string> subsequences( string str ){
    vector<string> ans;
    string output = "";
    int index = 0;
    solve( str, output, index ,ans);
    return ans;
}
