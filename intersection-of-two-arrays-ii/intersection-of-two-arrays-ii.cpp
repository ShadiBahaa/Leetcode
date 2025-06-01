class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2;
        for (int i : nums1){
            mp1[i]++;
        }
        for (int i : nums2){
            mp2[i]++;
        }
        vector<int> v;
        for (auto it : mp1){
            int x =  min(mp2[it.first],it.second);
            while(x--){
                v.push_back(it.first);
            }
        }
        return v;
    }
};