class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    map<pair<int,int>, bool> vis;
    void dfs(vector<vector<char>>& grid, int i, int j){
        vis[{i,j}] = true;
        for (int k = 0; k<4; ++k){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni < 0 || ni>=grid.size())continue;
            if(nj < 0 || nj>=grid[0].size())continue;
            if(!vis[{ni,nj}] && grid[ni][nj]=='1'){
                dfs(grid,ni,nj);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i<grid.size(); ++i){
            for (int j = 0; j<grid[i].size(); ++j){
                if(!vis[{i,j}] && grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};