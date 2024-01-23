class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for (vector<int> v:prerequisites){
            graph[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> q;
        for (int i = 0; i<numCourses; ++i){
            if (indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            --indegree[front];
            for (int child : graph[front]){
                --indegree[child];
                if (indegree[child]==0){
                    q.push(child);
                }
            }
        }
        for (int i = 0; i<numCourses; ++i){
            if (indegree[i] >= 0)return false;
        }
        return true;
    }
};