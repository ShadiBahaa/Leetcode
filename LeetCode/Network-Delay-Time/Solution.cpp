class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n + 1);
        for (auto& time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }

        const int INF = 1e9;
        vector<int> dist(n + 1, INF);
        dist[k] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue; 

            for (const auto& [v, w] : graph[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1; // unreachable node
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
