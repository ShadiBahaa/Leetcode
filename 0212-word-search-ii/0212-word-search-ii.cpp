class TrieNode{
    public:
    TrieNode * children[26];
    bool is_word;
    TrieNode(){
        for (int i = 0; i<26; ++i){
            children[i] = nullptr;
        }
        is_word = false;
    }
};

class Solution {
public:
    TrieNode * root = new TrieNode();
    void insert(string word){
        TrieNode * cur = root;
        for (char c : word){
            if (cur->children[c-'a'] == nullptr){
                cur->children[c-'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        cur->is_word = true;
    }
    void backtrack(vector<vector<char>>& board,int i, int j, int m, int n, TrieNode * node, vector<string>& res, string s){
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j]=='#')return;
        
        char c = board[i][j];
        node = node->children[c-'a'];
        if (node == nullptr)return;
        s += c;
        if (node->is_word){
            res.push_back(s);
            node->is_word = false;
        }
        
        board[i][j] = '#';
        
        backtrack(board,i-1,j,m,n,node,res,s);
        backtrack(board,i+1,j,m,n,node,res,s);
        backtrack(board,i,j+1,m,n,node,res,s);
        backtrack(board,i,j-1,m,n,node,res,s);
        
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string word : words){
            insert(word);
        }
        int m = board.size();
        int n = board[0].size();
        vector<string> v;
        TrieNode * node = root;
        vector<string> res;
        for (int i = 0; i<m; ++i){
            for (int j = 0; j<n; ++j){
                backtrack(board,i,j,m,n,node,res,"");
            }
        }
        return res;
    }
};