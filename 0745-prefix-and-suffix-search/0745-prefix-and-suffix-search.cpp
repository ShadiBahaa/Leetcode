class Trie{
    Trie * child[26];
    vector<int> indices;
    public:
    Trie(){
        memset(child,0,sizeof(child));
    }
    
    void insert(const string & str, int index){
        Trie * cur = this;
        for (char c : str){
            if(!cur->child[c-'a']){
                cur->child[c-'a'] = new Trie();
            }
            cur->child[c-'a']->indices.push_back(index);
            cur = cur->child[c-'a'];
        }
    }
    
    vector<int> get_positions(const string & str){
        Trie * cur = this;
        for (char c : str){
            if(!cur->child[c-'a']){
               return vector<int>();
            }
            cur = cur->child[c-'a'];
        }
        return cur->indices;
    }
};

class WordFilter {
public:
    Trie prefix;
    vector<string> orgi;
    WordFilter(vector<string>& words) {
        set<string> s;
        orgi = words;
        for (int i = words.size()-1; i>=0; --i){
            if(s.insert(words[i]).second){
                prefix.insert(words[i],i);
            }
        }
    }
    bool is_suffix(const string& str, const string& suf){
        if(str.size()<suf.size())return false;
        int i = suf.size()-1;
        int j = str.size()-1;
        while (i>=0 && j>=0){
            if(suf[i]!=str[j])return false;
            i--;
            j--;
        }
        return true;
    }
    int f(string pref, string suff) {
        vector<int> pre_list = prefix.get_positions(pref);
        for (int idx : pre_list){
            if(is_suffix(orgi[idx],suff)){
               return idx; 
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */