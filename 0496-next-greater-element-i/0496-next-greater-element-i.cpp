class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for (int i = 0; i<(int)nums1.size() ; ++i){
            int nx = -1;
            bool found = false;
            for (int j = 0; j<(int)nums2.size(); ++j){
                if (nums2[j]==nums1[i])found = true;
                if (found && nums2[j]>nums1[i]){
                    nx = nums2[j];
                    break;
                }
            }
            v.push_back(nx);
        }
        return v;
    }
};