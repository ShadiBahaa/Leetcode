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
            //cout<<"yes 1"<<endl;
            call1 = dp(i+1,false,num1[i],num2[i]);
        }
        if (prev1<num2[i] && prev2<num1[i]){
            //cout<<"yes 2"<<endl;
            call2 = 1 + dp(i+1,true,num2[i],num1[i]);
        }
        return mp[i][swapped] = min(call1,call2);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        num1 = nums1;
        num2 = nums2;
        for (int i = 0; i<100005; ++i){
            for (int j = 0; j<2; ++j){
                mp[i][j] = -1;
            }
        }
        return dp(0,false,-1,-1);
    }
};