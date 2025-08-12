class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cand;

    void solve(int idx, int target, vector<int>& cur) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (target < 0) return;

        for (int i = idx; i < cand.size(); ++i) {
            cur.push_back(cand[i]);
            solve(i, target - cand[i], cur); 
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cand = candidates;
        sort(cand.begin(), cand.end()); 
        vector<int> cur;
        solve(0, target, cur);
        return ans;
    }
};
