class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    map<pair<int,int>,bool> visited;
    void bfs(vector<vector<char>>& grid, int i , int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[{i,j}] = true;
        while (!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            for(int k = 0; k<4; ++k){
                int ni = cur.first + dx[k];
                int nj = cur.second + dy[k];
                if(ni<0 || ni>=grid.size())continue;
                if(nj<0 || nj>=grid[0].size())continue;
                if(!visited[{ni,nj}] && grid[ni][nj]=='1'){
                    q.push({ni,nj});
                    visited[{ni,nj}] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i<grid.size(); ++i){
            for (int j = 0; j<grid[i].size(); ++j){
                if(grid[i][j]=='1' && !visited[{i,j}]){
                    bfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};