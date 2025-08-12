class Solution {
public:
    struct Trie {
        Trie* children[26] = {};
        bool isWord = false;
        string word;
    };

    Trie* root;
    vector<string> ans;
    vector<vector<char>> brd;
    int m, n;

    void addWord(const string& s) {
        Trie* cur = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!cur->children[idx]) cur->children[idx] = new Trie();
            cur = cur->children[idx];
        }
        cur->isWord = true;
        cur->word = s;
    }

    void dfs(int r, int c, Trie* node, vector<vector<bool>>& vis) {
        if (r < 0 || r >= m || c < 0 || c >= n) return;
        if (vis[r][c]) return;

        char ch = brd[r][c];
        int idx = ch - 'a';
        if (!node->children[idx]) return;

        node = node->children[idx];
        if (node->isWord) {
            ans.push_back(node->word);
            node->isWord = false; 
        }

        vis[r][c] = true;
        dfs(r+1, c, node, vis);
        dfs(r-1, c, node, vis);
        dfs(r, c+1, node, vis);
        dfs(r, c-1, node, vis);
        vis[r][c] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        brd = board;
        m = board.size();
        n = board[0].size();

        root = new Trie();
        for (auto& w : words) addWord(w);

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(i, j, root, vis);
            }
        }

        return ans;
    }
};
