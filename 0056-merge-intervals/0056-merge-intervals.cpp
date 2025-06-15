class Solution {
public:
    bool static by(const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),by);
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        for (int i = 1; i<intervals.size(); ++i){
            vector<int> interval = intervals[i];
            if(interval[0] <= prev[1]){
                prev[1] = max(prev[1], interval[1]);
            }else{
                ans.push_back(prev);
                prev = interval;
            }
        }
        ans.push_back(prev);
        return ans;
    }
};