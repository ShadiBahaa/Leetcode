class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1 ;
        for (int ele: nums1)s1.insert(ele);
        unordered_set<int> s2 ;
        for (int ele: nums2)s2.insert(ele);
        vector<int> res;
        for (int ele: s1){
            if(s2.count(ele)){
                res.push_back(ele);
            }
        }
        return res;
    }
};