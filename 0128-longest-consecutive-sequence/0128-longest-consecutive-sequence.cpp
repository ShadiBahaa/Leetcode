class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size())return 0;
        set<int> s (nums.begin(),nums.end());
        int cur = 1;
        int ans = 1;
        auto it = s.begin();
        int prev = *it;
        it++;
        for (;it!=s.end();++it){
            if (*it-prev==1){
                cur++;
            }else {
                ans = max(cur,ans);
                cur = 1;
            }
            prev = *it;
        }
        return max(cur,ans);
    }
};