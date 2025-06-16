class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minStockValSoFar = 1e9, maxProfitValSoFar = -1;
        for (int price : prices){
            minStockValSoFar = min(minStockValSoFar,price);
            maxProfitValSoFar = max(maxProfitValSoFar,price-minStockValSoFar);
        }
        return maxProfitValSoFar;
    }
};
/*

[7,1,5,3,6,4]

minStockValSoFar : 7, 1, 1, 1, 1, 1 

maxProfitValSoFar: 0, 0, 4, 4, 5, 5

*/