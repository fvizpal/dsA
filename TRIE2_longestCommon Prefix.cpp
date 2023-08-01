/*
input : words
output : in these words what may be the largest common prefix

approach
 take first string
 compare it with all iother words 
 if found put it in ANS string
 return this ANS
*/

string longestCommonPrefix( vector<string> &arr, int n){

    string ans = "";
    //for traversing all charcters of the first string
    for( int i = 0; i < arr[0].length(); i++){
        char ch = arr[0][i];
        bool match = true;
        for ( int j = 1; j < n; j++){
            // not match
            if( arr[j].size() < i || ch != arr[j][i]){
                match = false;
                break;
            }
        }
        if(!match)
            break;
        else
            ans.push_back(ch);
    }

    return ans ;
} // but two lopes here O( m*n ) SC is O( m )


/*
approach 2: Solving using TRIE
 make a TRIE
 wherever a node has more than 1 child 
 stop ; and ch above these is the ans

*/ 

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for ( int i = 0; i < 26 ; i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(char ch){
        root = new TrieNode(ch);
    }

    //insertion
    void insertUtil( TrieNode* root, string word ){
        // base case
        if(word.length() == 0){
            root -> isTerminal = true;
        }

        // assuming all letters are capital
        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if( root -> children[index] != NULL){
            child = root -> children[index]; //bs aage bad jaao
        }
        else{
            //absent
            child = new TrieNode(word[0]); // make new if absent
            root -> childCount++;
            root -> children[index] = child; 
        }

        //recursion
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root, word); // what the fuck went wrong here why are there two arguments
    }

    void lcp( string str, string & ans){ // longestcommon prfix
        for ( int i = 0; i < str.length(0) ; i++){
            char ch = str[i];

            if( root -> childCount == 1){
                ans.push_back(ch);

                int index = ch - 'A';
                root = root -> children[index];
            } else{
                break;
            }
            if( root -> isTerminal){
                break;
            }
        }
    }

};


string longestCommonPrefix( vector<string> &arr, int n){
    Trie * t = new Trie('\0');

    // insert all strings
    for ( int i = 0; i < n; i++){
        t -> insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    lcp(first, ans);

    return ans;

} // bit nah purane wale se zyada efficient toh nhi h 
// both TC AND SC are O( n*m )
// previously SC was O( 1)




