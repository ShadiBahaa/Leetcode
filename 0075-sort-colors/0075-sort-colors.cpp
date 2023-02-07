class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i<nums.size(); ++i){
            int k = i;
            for (int j = i+1; j<nums.size(); ++j){
                if (nums[j]<nums[k])k = j;
            }
            swap(nums[i],nums[k]);
        }
    }
};