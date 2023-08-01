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
        insertWord(root, word);
    }

    void printSuggestions( TrieNode* curr , vector<string> &temp, string prefix){
        if( curr -> isTerminal){
            temp.push_back(prefix); // why we removed return from here
        }

        for( char ch = 'a'; ch <= 'z'; ch++){
            TrieNode* next = curr -> children[ch - 'a'];

            if( next != NULL){
                prefix.push_back(ch);
                printSuggestions(next , temp , prefix); // this is looping recursively to all the connected child nodes till terminal is reached 
                // when terminal is reached i.e we have a suggestion in the prefix // which is then pushed to suggestions vector // not uderstood here
                prefix.pop_back(); //this is done to backtrack to the previous level of the trie 
                // help !!!!
            }
        }
    }

    vector<vector<string>> getSuggestions( string str){
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for( int i = 0; i< str.length(); i++){
            char lastch = str[i]; // lastch variable me pehla char dal rhe

            prefix.push_back(lastch); // amd then pushing it to prefix

            //check for lastch
            TrieNode* curr = prev-> children[lastch -'a']; // asking prev bhai if he has lastch naam ki node

            //if not found
            if( curr == NULL){
                break;
            }

            // if found  // print all suggestions for it
            vector<string> temp;
            printSuggestions(curr,temp , prefix); 

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }

};

vector<vector<string>> phoneDirec( vector<string> &contactList, string &queryStr ){
    Trie* t =new Trie();

    //insert all contact in trie
    for( int i = 0; i < contactList.size(); i++){
        string str = contactList[i];
        t -> insertWord(str);
    }

    //return ans
    return t -> getSuggestions(queryStr);

} // TC is O( n* m^2) // and SC is 
//