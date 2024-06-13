class KthLargest {
public:
    int k;
    vector<int> nums;
    int n;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        n = nums.size();
        sort(this->nums.begin(),this->nums.end());
    }
    
    int add(int val) {
        auto it = lower_bound(nums.begin(),nums.end(),val);
        if (it == nums.end()){
            nums.push_back(val);
        }else {
            nums.insert(it,val);
        }
        n++;
        return nums[n-k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */