class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        vector<long long> v1 (grid[0].size(),0);
        vector<long long> v2 (grid[1].size(),0);
        v1[0] = grid[0][0];
        v2[0] = grid[1][0];
        long long ans = LONG_MAX;
        for (int i = 1; i<v1.size(); ++i){
            v1[i] = v1[i-1]+grid[0][i];
            v2[i] = v2[i-1]+grid[1][i];
        }
        for (int i = 0; i<v1.size(); ++i){
            long long top = v1[(int)v1.size()-1]-v1[i];
            long long bottom = (i>0)?v2[i-1]:0;
            long long sec = max(top,bottom);
            ans = min(sec,ans);
        }
        return ans;
    }
};