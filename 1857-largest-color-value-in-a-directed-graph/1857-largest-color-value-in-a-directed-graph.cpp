class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> indegree(n);
        vector<vector<int>> graph(n);
        for (vector<int> edge: edges){
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i<colors.size(); ++i){
            if (indegree[i]==0){
                q.push(i);
            }
        }
        int nodes = 0;
        int res = 0;
        vector<vector<int>> ans(n,vector<int>(26));
        while (!q.empty()){
            int front = q.front();
            q.pop();
            ans[front][colors[front]-'a']++;
            res = max(res, ans[front][colors[front]-'a']);
            nodes++;
            for (int child: graph[front]){
                if (--indegree[child]==0){
                    q.push(child);
                }
                for (int i = 0; i<26; ++i){
                    ans[child][i] = max(ans[child][i],ans[front][i]);
                }
            }
        }
        if (nodes != colors.size())return -1;
        return res;
    }
};