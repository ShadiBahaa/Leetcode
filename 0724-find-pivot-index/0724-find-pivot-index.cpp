class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        sum =  accumulate(nums.begin(),nums.end(),sum);
        int left = 0;
        int right = 0;
        for (int i = 0; i<(int)nums.size(); ++i){
            if (i>=1)left+=nums[i-1];
            right = sum-left-nums[i];
            if (right==left)return i;
        }
        return -1;
    }
};