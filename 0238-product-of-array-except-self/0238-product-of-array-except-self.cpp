class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int cnt = count(nums.begin(),nums.end(),0);
        if (cnt>1 || cnt==nums.size())return vector<int>(nums.size(),0);
        if (cnt==1){
            long long prod = 1;
            for (int x:nums){
                if (x)prod*=x;
            }
            vector<int> v;
            for (int x:nums){
                if (!x){
                    v.push_back(prod);
                }else {
                    v.push_back(0);
                }
            }
            return v;
        }
        long long prod = 1;
        for (int x:nums){
            prod*=x;
        }
        vector<int> v;
        for (int x:nums){
            v.push_back(prod/x);
        }
        return v;
    }
};