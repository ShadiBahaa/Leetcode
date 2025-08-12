class Solution {
public:
    vector<vector<int>> paths;
    vector<vector<int>> gra;
    void dfs(int src, int dest, vector<int> path, vector<bool> vis){
        if(src == dest){
            paths.push_back(path);
            return;
        }
        vis[src] = true;
        for (int child : gra[src]){
            if(!vis[child]){
                path.push_back(child);
                dfs(child,dest,path,vis);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size());
        gra = graph;
        dfs(0,graph.size()-1,{0},vis);
        return paths;
    }
};