class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    static bool check(int i, int j, int m, int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        map<pair<int,int>,vector<pair<int,int>>> graph;
        int m = matrix.size();
        int n = matrix[0].size();
        map<pair<int,int>,int> indegree;
        for (int i = 0; i<m; ++i){
            for (int j = 0; j<n; ++j){
                for (int k = 0; k <4; ++k){
                    int newx = i + dx[k];
                    int newy = j + dy[k];
                    if (check(newx,newy,m,n) && matrix[newx][newy]>matrix[i][j]){
                        graph[{i,j}].push_back({newx,newy});
                        indegree[{newx,newy}]++;
                    }
                }
            }
        }
        queue<pair<int,int>> q;
        for (int i = 0; i<m; ++i){
            for (int j = 0; j<n; ++j){
                if (!indegree[{i,j}]){
                    q.push({i,j});
                }
            }
        }
        int ans = 0;
        while (!q.empty()){
            int sz = q.size();
            ans++;
            while (sz--){
                pair<int,int> front = q.front();
                q.pop();
                for (pair<int,int> child: graph[front]){
                    if (--indegree[child] == 0){
                        q.push(child);
                    }
                }
            }
        }
        return ans;
    }
};