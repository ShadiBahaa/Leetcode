class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        vector<int> dp;
        for (int i = 0; i<scores.size(); ++i){
            v.push_back({scores[i],ages[i]});
        }
        sort(v.begin(),v.end());
        for (pair<int,int> p : v){
            dp.push_back(p.first);
        }
        for (int i = 0; i<v.size(); ++i){
            int i_score = v[i].first;
            int i_age = v[i].second;
            for (int j = 0; j<i; ++j){
                int j_age = v[j].second;
                if (j_age <= i_age){
                    dp[i] = max(dp[i],dp[j]+i_score);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};