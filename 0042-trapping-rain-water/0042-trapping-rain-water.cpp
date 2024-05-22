class Solution {
public:
    int trap(vector<int>& height) {
        int maxi = 0;
        vector<int> left(height.size());
        vector<int> right(height.size());
        for (int i = 0; i < height.size(); ++i){
            left[i] = maxi;
            maxi = max(maxi,height[i]);
        }
        maxi = 0;
        for (int i = (int)height.size()-1; i>=0; --i){
            right[i] = maxi;
            maxi = max(maxi,height[i]);
        }
        int cnt = 0;
        for (int i = 0; i<height.size(); ++i){
            cnt += max(min(left[i],right[i])-height[i],0);
        }
        return cnt;
    }
};