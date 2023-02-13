class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int,int>,long long> mp;
        long long ans = 0;
        for (vector<int> x:rectangles){
            int gcd = __gcd(x[0],x[1]);
            mp[{x[0]/gcd,x[1]/gcd}]++;
        }
        for (auto it= mp.begin(); it!=mp.end(); ++it){
            ans+=(it->second*(it->second-1)/2);
        }
        return ans;
    }
};