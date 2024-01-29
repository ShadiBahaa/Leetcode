class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        vector<int> completion(n);
        for (vector<int> relation: relations){
            graph[--relation[0]].push_back(--relation[1]);
            indegree[relation[1]] ++;
        }
        queue<int> q;
        for (int i = 0; i<n; ++i){
            if (indegree[i] == 0){
                q.push(i);
            }
        }
        while (!q.empty()){
            int sz = q.size();
            int tmp = 0;
            while (sz--){
                int front = q.front();
                completion[front] += time[front];
                q.pop();
                for (int child: graph[front]){
                    if (--indegree[child] == 0){
                        q.push(child);
                    }
                    completion[child] = max(completion[child],completion[front]);
                }
            }
        }
        return *max_element(completion.begin(),completion.end());
    }
};