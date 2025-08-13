class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) group[i] = m++;
        }

        vector<vector<int>> itemGraph(n), groupGraph(m);
        vector<int> itemIndegree(n, 0), groupIndegree(m, 0);

        for (int i = 0; i < n; ++i) {
            for (int prev : beforeItems[i]) {
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;

                if (group[i] != group[prev]) {
                    groupGraph[group[prev]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        auto topoSort = [](vector<vector<int>>& graph, vector<int>& indegree) {
            vector<int> result;
            queue<int> q;
            for (int i = 0; i < indegree.size(); ++i) {
                if (indegree[i] == 0) q.push(i);
            }
            while (!q.empty()) {
                int u = q.front(); q.pop();
                result.push_back(u);
                for (int v : graph[u]) {
                    if (--indegree[v] == 0) q.push(v);
                }
            }
            return result;
        };

        vector<int> groupOrder = topoSort(groupGraph, groupIndegree);
        if (groupOrder.size() != m) return {};

        vector<int> itemOrder = topoSort(itemGraph, itemIndegree);
        if (itemOrder.size() != n) return {}; 

        unordered_map<int, vector<int>> itemsInGroup;
        for (int item : itemOrder) {
            itemsInGroup[group[item]].push_back(item);
        }

        vector<int> result;
        for (int g : groupOrder) {
            for (int item : itemsInGroup[g]) {
                result.push_back(item);
            }
        }
        return result;
    }
};
