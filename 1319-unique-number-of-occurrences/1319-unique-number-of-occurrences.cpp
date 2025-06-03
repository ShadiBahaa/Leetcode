class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for (int ele : arr){
            mp[ele]++;
        }
        set<int> s;
        for (auto it : mp){
            s.insert(it.second);
        }
        return mp.size() == s.size();
    }
};