class Solution {
public:
    bool test(vector<int>&piles, int h, int mid){
        long long hours = 0;
        for (int pile : piles){
            hours += ceil(double(pile) / mid);
        }
        //cout<<mid<<" "<<hours<<endl;
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(),piles.end());
        int low = 1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(test(piles,h,mid)){
                ans = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return ans;
    }
};