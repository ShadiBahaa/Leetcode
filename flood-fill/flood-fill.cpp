class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    map<pair<int,int>,bool> vis;
    void dfs(vector<vector<int>>& image, int sr, int sc,int original, int color){
        vis[{sr,sc}] = true;
        for(int k = 0; k<4 ; ++k){
            int ni = sr + dx[k];
            int nj = sc + dy[k];
            if(ni<0 || ni>=image.size())continue;
            if(nj<0 || nj>=image[0].size())continue;
            if(!vis[{ni,nj}] && image[ni][nj]==original){
                image[ni][nj] = color;
                dfs(image,ni,nj,original,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        image[sr][sc] = color;
        dfs(image,sr,sc,original,color);
        return image;
    }
};