class Solution {
public:
    // 3-0
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        sort(nums.begin(),nums.end());
        for (int i = 0 ; i<nums.size(); ++i){
            if ((i + k-1) < nums.size()){
                ans = min(ans,nums[i+k-1]-nums[i]);
            }
        }
        return ans;
    }
};