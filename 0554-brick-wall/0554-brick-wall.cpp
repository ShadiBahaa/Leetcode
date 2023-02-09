class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int> mp;
        for (vector<int> v:wall){
            int sum = 0;
            for (int i = 0; i<(int)v.size()-1; ++i){
                sum+=v[i];
                mp[sum]++;
            }
        }
        int ans = 0;
        for (pair<int,int> pa: mp){
            ans = max(ans,pa.second);
            cout<<pa.first<<" "<<pa.second<<endl;
        }
        return (int)wall.size()-ans;
    }
};