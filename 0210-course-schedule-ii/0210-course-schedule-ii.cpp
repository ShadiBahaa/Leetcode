class Solution {
public:
    bool dfs(int node, vector<int>& order,vector<int>& start,vector<int>& finish,vector<vector<int>> graph, int& time){
        start[node] = time++;
        for (int child:graph[node]){
            if (start[child]==-1){
                if(dfs(child,order,start,finish,graph,time)){
                    return true;
                }
            }else if (finish[child]==-1) {
                return true;
            }
        }
        finish[node] = time++;
        order.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<int> start(numCourses,-1);
        vector<int> finish(numCourses,-1);
        vector<vector<int>> graph(numCourses);
        for (vector<int> edge : prerequisites){
            graph[edge[1]].push_back(edge[0]);
        }
        int time = 1;
        for (int i = 0; i<numCourses; ++i){
            if (start[i]==-1){
                if (dfs(i,order,start,finish,graph,time)){
                    return {};
                }
            }
        }
        reverse(order.begin(),order.end());
        return order;
    }
};