class Solution {
public:
    static bool fun(pair<int,int> &a, pair<int,int> &b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int,int> mp;
        vector<int> v;
        for (int elem:nums)mp[elem]++;
        vector<pair<int,int>> to_sort;
        for (auto it:mp){
            to_sort.push_back({it.first,it.second});
        }
        sort(to_sort.begin(),to_sort.end(),fun);
        auto it = to_sort.begin();
        while (k--){v.push_back((it->first));it++;}
        return v;
    }
};