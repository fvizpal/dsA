
class TrieNode{
    public:
    char val;
    TrieNode* children[26]; // because this is for alphabets // can be for other too
    bool isterminal;

    TrieNode(char ch){
        val = ch;
        for( int i = 0; i< 26; i++){
            children[i] = NULL;
        }
        isterminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    //the constructor
    Trie () {
        root = new TrieNode('\0'); // i.e. starting our root from a NULL character
    }

    void insertUtil (TrieNode* root, string word ){
        // base case
        if (word.length() == 0){
            root->isTerminal = true;
        }

        // assuming all letters are capital
        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if (root->children[index] != NULL){
            child = root->children[index]; //bs aage bad jaao
        }
        else {
            //absent
            child = new TrieNode(word[0]); // make new if absent
            root->children[index] = child; 
        }

        //recursion
        insertUtil (child, word.substr(1));
    }
    
    void insertWord (string word){
        insertUtil (root, word);
    }

    bool searchutil (TrieNode* root , string word){
        // base case
        if (word.length() == 0){
            return root -> isTerminal 
        } // FOR PREFIX SEARCH return here simply TRUE since we do not need to go till terminal

        int index = word[0] - 'A';
        TrieNode* child;

        // if present case
        if (root-> children[index] != NULL){
            child = root -> children[index];
        }
        else {
            // absent case
            return false; 
        }

        // recursive call
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchutil(root , word);
    }

    // implement a starts with function too // input is a prefix and output bool if
    // there is a milta julta word

};
// TC in insertion will be O( l ) where l is length of word
// in removing a word TC is O( l )
// and searching too O( l )

/* to remove a word{
    just search the word
    and make its terminal node not NULL
    // but this way space still is being wasted
    // so how to optimise space

} */
// The dictionary problem

int main(){

}