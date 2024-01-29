class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int max_colors = 63;
        vector<int> rmin(max_colors,max_colors);
        vector<int> cmin(max_colors,max_colors);
        vector<int> rmax(max_colors,-1);
        vector<int> cmax(max_colors,-1);
        int m = targetGrid.size();
        int n = targetGrid[0].size();
        for (int r = 0; r<m ; ++r){
            for (int c = 0; c<n; ++c){
                int color = targetGrid[r][c];
                rmin[color] = min(rmin[color],r);
                rmax[color] = max(rmax[color],r);
                cmin[color] = min(cmin[color],c);
                cmax[color] = max(cmax[color],c);
            }
        }
        vector<vector<int>> graph(max_colors);
        vector<int> indegree(max_colors);
        for (int color = 1; color<=60 ; ++color){
            for (int r = rmin[color]; r<=rmax[color]; r++){
                for (int c = cmin[color]; c<=cmax[color]; c++){
                    if (targetGrid[r][c]!=color){
                        graph[color].push_back(targetGrid[r][c]);
                        indegree[targetGrid[r][c]]++;
                    }
                }
            }
        }
        queue<int> q;
        for (int i = 1; i<=60; ++i){
            if (indegree[i]==0){
                q.push(i);
            }
        }
        while (!q.empty()){
            int front = q.front();
            q.pop();
            for (int child: graph[front]){
                if (--indegree[child]==0){
                    q.push(child);
                }
            }
        }
        for (int i = 1; i<=60; ++i){
            for (int child: graph[i]){
                if (indegree[child]>0)return false;
            }
        }
        return true;
    }
};