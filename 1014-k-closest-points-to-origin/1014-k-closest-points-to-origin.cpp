class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i<points.size(); ++i){
            pq.push(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
        }
        set<int> ans;
        while(k--){
            ans.insert(pq.top());
            pq.pop();
        }
        vector<vector<int>> ret;
        for (int i = 0; i<points.size(); ++i){
            if(ans.count(points[i][0]*points[i][0] + points[i][1]*points[i][1])){
                ret.push_back(points[i]);
            }
        }
        return ret;
    }
};