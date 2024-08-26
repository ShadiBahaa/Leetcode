class Solution {
public:
    map<string,bool> vis;
    map<string,vector<pair<string,double>>> graph;
    double bfs(string start, string end){
        queue<pair<string,double>> q;
        q.push({start,1});
        vis[start] = true;
        while (!q.empty()){
            pair<string,double> cur = q.front();
            q.pop();
            if (cur.first == end){
                return cur.second;
            }
            
            for (pair<string,double> child : graph[cur.first]){
                if (!vis[child.first]){
                vis[child.first] = true;
                q.push({child.first,child.second * cur.second});}
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> mp;
        vector<double> ans;
        for (int i = 0; i<equations.size(); ++i){
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        graph = mp;
        for (vector<string> query : queries){
            if (mp.count(query[0])){
                vis.clear();
                ans.push_back(bfs(query[0],query[1]));
            }else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};