class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int bfs(vector<vector<int>>& mat, int i , int j, map<pair<int,int>,bool>& mp){
        if (mat[i][j] == 0)return 0;
        int count = 1e9;
        mp[{i,j}] = true;
        for (int k = 0; k<4; ++k){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni < 0 || ni >= mat.size()) continue;
            if(nj < 0 || nj >= mat[0].size()) continue;
            if(!mp[{ni,nj}]) count = min(1+bfs(mat,ni,nj,mp),count);
        }
        return count;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dist(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        queue<pair<int,int>> q;
        for(int i = 0; i<mat.size(); ++i){
            for(int j = 0; j<mat[i].size(); ++j){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            for (int k = 0; k<4; ++k){
                int ni = cur.first + dx[k];
                int nj = cur.second + dy[k];
                if(ni < 0 || ni >= mat.size()) continue;
                if(nj < 0 || nj >= mat[0].size()) continue;
                if(dist[ni][nj] > (dist[cur.first][cur.second]+1)){
                    dist[ni][nj]  = dist[cur.first][cur.second]+1;
                    q.push({ni,nj});
                }
            }
        }
        return dist;
    }
};