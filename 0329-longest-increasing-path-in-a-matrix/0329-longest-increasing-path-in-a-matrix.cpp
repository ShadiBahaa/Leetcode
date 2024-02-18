class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    static bool is_valid(int& i, int& j, int& m, int& n){
        return i >= 0 && i < m && j >= 0 && j<n;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<pair<int,int>,vector<pair<int,int>>> graph;
        vector<vector<int>> indegree(m,vector<int>(n));
        for (int i = 0; i<m; ++i){
            for (int j = 0; j<n; ++j){
                for (int k = 0; k<4; ++k){
                    int newi = i + dx[k];
                    int newj = j + dy[k];
                    if (is_valid(newi,newj,m,n) && matrix[newi][newj]>matrix[i][j]){
                        graph[{i,j}].push_back({newi,newj});
                        indegree[newi][newj]++;
                    }
                }
            }
        }
        queue<pair<int,int>> q;
        for (int i = 0; i<m; ++i){
            for (int j = 0; j<n; ++j){
                if (indegree[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int levels = 0;
        while (!q.empty()){
            levels ++;
            int sz = q.size();
            while (sz--){
                pair<int,int> front = q.front();
                q.pop();
                for (pair<int,int> child : graph[front]){
                    if (--indegree[child.first][child.second]==0)
                    q.push(child);
                }
            }
        }
        return levels;
    }
};