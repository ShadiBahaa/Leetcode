class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> pre1, pre2;
        int n = nums.size();
        pre1.push_back(nums[0]);
        pre2.push_back(nums[n-1]);
        for (int i = 1; i<n; ++i){
            pre1.push_back(nums[i]+pre1[i-1]);
        }
        int j = 0;
        for (int i = n-2; i>=0; --i){
            pre2.push_back(nums[i]+pre2[j]);
            j++;
        }
        reverse(pre2.begin(),pre2.end());
        for(int i = 0; i<n; ++i){
            if(pre1[i]==pre2[i]){
                return i;
            }
        }
        return -1;
    }
};