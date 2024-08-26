class Solution {
public:
    int totalMoney(int n) {
        int mon = 0;
        int ans = 0;
        for (int i  = 1; i<=n; ++i){
            if (i%7 == 1)mon++;
            ans += (i-1)%7 + mon;
        }
        return ans;
    }
};