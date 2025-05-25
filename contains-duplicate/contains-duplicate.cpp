class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int ele : nums){
            if (s.count(ele))return true;
            s.insert(ele);
        }
        return false;
    }
};