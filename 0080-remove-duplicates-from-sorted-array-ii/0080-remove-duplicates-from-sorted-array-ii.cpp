class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int ans = nums.size();
        for (int i = 1; i<nums.size(); ++i){
            if (nums[i]==nums[i-1]){
                cnt++;
            }else {
                cnt = 1;
            }
            if (cnt > 2){
                int val = nums[i];
                nums.erase(nums.begin()+i);
                //nums.push_back(val);
                ans--;
                cnt--;
                --i;
            }
        }
        return ans;
    }
};