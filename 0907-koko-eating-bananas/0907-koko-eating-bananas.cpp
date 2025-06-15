class Solution {
public:
    bool tryy(int mid, vector<int>& piles, int h){
        long long count = 0;
        for(int pile : piles){
            if(pile <= mid)count++;
            else count += ceil(double(pile) / mid);
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1e9;
        sort(piles.begin(),piles.end());
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            //cout<<left<<" "<<mid<<" "<<right<<endl;
            if(tryy(mid,piles,h)){
                right = mid - 1;
                ans = mid;
            }else {
                left = mid + 1;
            }
        }
        return ans;
    }
};