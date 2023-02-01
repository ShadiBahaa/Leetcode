class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        for (int i = 0; i<(int)flowerbed.size(); ++i){
            if (flowerbed[i]==0){
                if (i>=1 && flowerbed[i-1]==1){
                    continue;
                }
                if (i<=(int)flowerbed.size()-2 && flowerbed[i+1]==1){
                    continue;
                }
                cnt++;
                flowerbed[i] = 1;
            }
        }
        return (cnt>=n)?true:false;
    }
};