class Solution {
public:
    int m;
    vector<int> tmp;
    int can(int mid){
        int subs = 0;
        int cur_sum = 0;
        for (int ele : tmp){
            cur_sum += ele;
            if (cur_sum > mid){
                subs++;
                cur_sum = ele;
            }
        }
        return (subs+1)<=m;
    }
    int splitArray(vector<int>& nums, int k) {
        tmp = nums;
        m = k;
        int left = *max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(),nums.end(),0);
        int res = right;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (can(mid)){
                res = mid;
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return res;
    }
};