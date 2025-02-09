class Solution {
public:
    
    long long local = 0;
    long long merge(vector<int>& nums, int start, int mid, int end){
       int global = 0;
        int i = start, j = mid + 1, k = 0;
        vector<int> temp(end - start + 1);

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
                global += (mid - i + 1); 
            }
        }

        while (i <= mid) temp[k++] = nums[i++];
        while (j <= end) temp[k++] = nums[j++];
        
        for (int x = 0; x < temp.size(); x++) 
            nums[start + x] = temp[x];

        return global;
    }
    long long merge_sort(vector<int>& nums, int start, int end){
        if(start>=end)return 0;
        int global = 0;
        int mid = start + (end-start)/2;
        global+= merge_sort(nums,start,mid);
        global+= merge_sort(nums,mid+1,end);
        global += merge(nums,start,mid,end);
        return global;
    }
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < (nums.size()-1); ++i){
            if(nums[i] > nums[i+1]){
                local++;
            }
        }
        long long global =  merge_sort(nums,0,nums.size()-1);
        return global==local;
    }
};