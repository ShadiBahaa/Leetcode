class Solution {
public:
    vector<int> num1;
    vector<int> num2;  
    int mp[100005][2];
    int dp(int i,bool swapped, int prev1, int prev2){
        if (i>=(num1.size()))return 0;
        if (mp[i][swapped]!=-1)return mp[i][swapped];
        int call1 = 1e9,call2 = 1e9;
        if (prev1 < num1[i] && prev2 < num2[i]){
            call1 = dp(i+1,false,num1[i],num2[i]);
        }
        if (prev1<num2[i] && prev2<num1[i]){
            call2 = 1 + dp(i+1,true,num2[i],num1[i]);
        }
        return mp[i][swapped] = min(call1,call2);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        num1 = nums1;
        num2 = nums2;
        /*for (int i = 0; i<100005; ++i){
            for (int j = 0; j<2; ++j){
                mp[i][j] = -1;
            }
        }*/
        mp[num1.size()][0] = mp[num1.size()][1] =  0;
        for (int i = num1.size()-1; i>=0; --i){
            for (int swapped = 0; swapped<2; ++swapped){
                int prev1 = ((i-1)<0)?-1:num1[i-1];
                int prev2 = ((i-1)<0)?-1:num2[i-1];
                if (swapped){
                    swap(prev1,prev2);
                }
                int call1 = 1e9,call2 = 1e9;
                if (prev1 < num1[i] && prev2 < num2[i]){
                    call1 = mp[i+1][0];
                }
                if (prev1<num2[i] && prev2<num1[i]){
                    call2 = 1 + mp[i+1][1];
                }
                mp[i][swapped] = min(call1,call2);
            }
        }
        return mp[0][0];
        //return dp(0,false,-1,-1);
    }
};