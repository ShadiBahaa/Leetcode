class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size()==1){
            return nums[0]==target;
        }
        if (nums[0]==target){
            return true;
        }
        int prev = nums[0];
        int i = 1;
        while ((i*2) <= nums.size()){
            i*=2;
            int idx = i-1;
            if (target<=prev && target>=nums[idx] || (target>=prev && target<=nums[idx]))break;
            prev= nums[idx];
        }
        i/=2;
        int idx = i-1;
        while (idx<nums.size()){
            if (nums[idx]==target)return true;
            idx++;
        }
        return false;
    }
};