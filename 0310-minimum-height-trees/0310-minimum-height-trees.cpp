class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1){
            return {0};
        }
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for (vector<int> edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[1]]++;
            indegree[edge[0]]++;
        }
        queue<int> q;
        int total = 0;
        for (int i = 0; i<n; ++i){
            if (indegree[i] == 1){
                q.push(i);
            }
        }
        
            while(n>2){
                int level = q.size();
                n -= level;
                while (level--){
                    int front = q.front();
                    q.pop();
                    for (int child:graph[front]){
                        if (--indegree[child]==1)q.push(child);
                    }
                }
            }
        vector<int> ans;
        while (!q.empty()){
            ans.push_back(q.front());q.pop();
        }
        return ans;
    }
};