class Trie {
public:
    Trie * nodes[26] = {nullptr};
    bool isComplete = false;
    Trie() {
    }
    
    void insert(string word) {
        Trie * cur = this;
        for(char c : word){
            if(!cur->nodes[c-'a'])cur->nodes[c-'a'] = new Trie();
            cur = cur->nodes[c-'a'];
        }
        cur->isComplete = true;
    }
    
    bool search(string word) {
        Trie * cur = this;
        for(char c : word){
            if(!cur->nodes[c-'a'])return false;
            cur = cur->nodes[c-'a'];
        }
        return cur->isComplete;
    }
    
    bool startsWith(string prefix) {
        Trie * cur = this;
        for (char c : prefix){
            if(!cur->nodes[c-'a'])return false;
            cur = cur->nodes[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */