class Solution {
public:
    bool sub_sum(int idx, vector<int> &values, int target, map<pair<int,int>,int> & mp)
{
    if (target < 0)
    {
        return false;
    }
    if (target == 0)
    {
        return true;
    }
    if (idx == (int)values.size())
        return false;
    if (mp.count({idx, target}))
        return mp[{idx, target}];
    if (sub_sum(idx + 1, values, target, mp)){
        return mp[{idx, target}] = true;
    }
    return mp[{idx, target}] = sub_sum(idx + 1, values, target - values[idx], mp);
}
    bool canPartition(vector<int>& nums) {
        map<pair<int,int>,int> dp;
        int total = accumulate(nums.begin(),nums.end(),0);
        if (total % 2) return false;
        return sub_sum(0,nums,total/2,dp);
    }
};