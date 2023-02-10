class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        map<int,int> mp;
        mp[0]++;
        int sum = 0;
        for (int n:nums){
            sum+=n;
            int diff = sum-k;
            ans+= mp[diff];
            mp[sum]++;
        }
        return ans;
    }
};