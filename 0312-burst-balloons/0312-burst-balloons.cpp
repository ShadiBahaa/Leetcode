class Solution {
public:
    int mp[305][305];
    vector<int> num;
    int dp(int start, int end){
        if (start > end)return 0;
        if (mp[start][end]!=-1) return mp[start][end];
        int ans = INT_MIN;
        for (int k = start; k<=end; ++k){
            int cost = num[start-1] * num[k] * num[end+1];
            int sub1 = dp(start,k-1);
            int sub2 = dp(k+1,end);
            ans = max(ans,cost + sub1 + sub2);
        }
        return mp[start][end] = ans;
    }
    int maxCoins(vector<int>& nums) {
        num = nums;
        num.insert(num.begin(),1);
        num.push_back(1);
        memset(mp,-1,sizeof(mp));
        return dp(1,num.size()-2);
    }
};