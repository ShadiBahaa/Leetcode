class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Push all initially rotten oranges
        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        int minutes = 0;

        while (!q.empty()) {
            int sz = q.size();     
            bool changed = false;  

            for (int k = 0; k < sz; ++k) {
                auto cur = q.front(); q.pop();

                for (int i = 0; i < 4; ++i) {
                    int newi = cur.first + dx[i];
                    int newj = cur.second + dy[i];

                    if (newi >= 0 && newi < m && newj >= 0 && newj < n) {
                        if (!vis[newi][newj] && grid[newi][newj] == 1) {
                            q.push({newi, newj});
                            grid[newi][newj] = 2;
                            vis[newi][newj] = true;
                            changed = true;
                        }
                    }
                }
            }

            if (changed) minutes++;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return minutes;
    }
};
