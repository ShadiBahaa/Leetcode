class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        map<char,set<string>> mp;
        for (string idea : ideas){
            mp[idea[0]].insert(idea.substr(1));
        }
        long long ans = 0;
        for (char c1 = 'a' ; c1 <= 'z'; ++c1){
            for (char c2 = c1 + 1; c2 <= 'z'; ++c2){
                int intersections = 0;
                for (string suffix : mp[c1]){
                    if (mp[c2].count(suffix))intersections++;
                }
                long long dis1 = mp[c1].size() - intersections;
                long long dis2 = mp[c2].size() - intersections;
                ans += dis1 * dis2 * 2;
            }
        }
        return ans;
    }
};