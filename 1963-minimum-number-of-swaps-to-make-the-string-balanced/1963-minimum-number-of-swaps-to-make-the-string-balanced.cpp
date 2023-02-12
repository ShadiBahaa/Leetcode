class Solution {
public:
    int minSwaps(string s) {
        int close = 0;
        int ans = 0;
        for (char x:s){
            (x=='[')?close--:close++;
            ans = max(ans,close);
        }
        return (ans+1)/2;
    }
};