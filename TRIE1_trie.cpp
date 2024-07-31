
class TrieNode {
    public:

    int val;
    vector<TrieNode*> childs;
    bool isTerminal;

    TrieNode(char ch) {
        val = ch;
        childs.resize(26, nullptr);
        isTerminal = false;
    }
};
class Trie {
public:
TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* node, string s) {
        if(s.size() == 0) {
            node->isTerminal = true;
        }

        TrieNode* child;
        int ind = s[0] - 'a';

        if(node->childs[ind] == nullptr) {
            child = new TrieNode(s[0]);
            node->childs[ind] = child;
        }
        else {
            child = node->childs[ind];
        }

        insertUtil(child, s.substr(1));
    }
    void insert(string s) {
        insertUtil(root, s);
    }

    bool searchUtil(TrieNode* node, string s, bool isPrefix = false) {
        if(s.size() == 0) {
            if(isPrefix) return true;
            return node->isTerminal;
        }

        TrieNode* child;
        int ind = s[0] - 'a';

        if(node->childs[ind] == nullptr) {
            return false;
        }

        child = node->childs[ind];
        searchUtil(child, s.substr(1), isPrefix);
    }
    bool search(string s) {
        searchUtil(root, s);
    }

    bool prefix(string s) {
        return searchUtil(root, s, true);
    }
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