class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<>
        > pq;

        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = visited[m-1][j] = true;
        }

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int water = 0;

        while (!pq.empty()) {
            auto [h, pos] = pq.top(); pq.pop();
            int r = pos.first, c = pos.second;

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n || visited[nr][nc]) continue;
                visited[nr][nc] = true;
                water += max(0, h - heightMap[nr][nc]);
                pq.push({max(h, heightMap[nr][nc]), {nr, nc}});
            }
        }

        return water;
    }
};
