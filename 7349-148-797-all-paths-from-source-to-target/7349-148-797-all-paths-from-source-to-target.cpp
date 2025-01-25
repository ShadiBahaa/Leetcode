class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> graphy;
    int n;
    void backtrack(vector<int> cur , int i){
        if(i == n-1){
            ans.push_back(cur);
            return;
        }
        for(int child : graphy[i]){
            cur.push_back(child);
            backtrack(cur,child);
            cur.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        graphy = graph;
        backtrack({0},0);
        return ans;
    }
};