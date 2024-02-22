class Solution {
public:
    int lis(int i, map<int,int> & ans,int n,vector<int>& nums){
        if (ans.count(i))return ans[i];
        int res,maxi = 0;
        if (i == -1)res = 0;
        else res = 1;
        for (int j = i + 1; j<n; ++j){
            if (i==-1 || nums[j]>nums[i]){
                ans[j] = lis(j,ans,n,nums);
                maxi = max(ans[j],maxi);
            }
        }
        res+=maxi;
        return ans[i]=res;
    }
    int lengthOfLIS(vector<int>& nums) {
        map<int,int> ans;
        return lis(-1,ans,nums.size(),nums);
    }
};