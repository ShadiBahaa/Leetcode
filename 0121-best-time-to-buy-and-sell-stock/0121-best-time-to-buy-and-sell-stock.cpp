class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxi;
        vector<int> mini;
        int tmp = -1;
        for (int i = (prices.size()-1); i>=0; --i){
            maxi.push_back(max(prices[i],tmp));
            tmp = max(prices[i],tmp);
        }
        tmp = 1e9;
        for (int i : prices){
            mini.push_back(min(i,tmp));
            tmp = min(i,tmp);
        }
        int dif = 0;
        int i = prices.size()-1;
        int j = 0;
        while(i>=0 && j<=((int)prices.size()-1)){
            dif = max(dif,maxi[i]-mini[j]);
            i--; j++;
        }
        return dif;
    }
};