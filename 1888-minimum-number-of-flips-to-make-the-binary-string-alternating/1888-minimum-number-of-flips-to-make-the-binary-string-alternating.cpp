class Solution {
public:
    int minFlips(string s) {
        string ss = s + s;
        string alt1, alt2;
        for (int i = 0; i<ss.size(); ++i){
            if (i%2){
                alt1 += '0';
                alt2 += '1';
            }else {
                alt1 += '1';
                alt2 += '0';
            }
        }
        int diff1 = 0 , diff2 = 0;
        int left = 0;
        int ans = 1e9;
        for (int right = 0; right<ss.size(); ++right){
            if (ss[right]!=alt1[right]){
                diff1 ++;
            }
            if (ss[right]!=alt2[right]){
                diff2 ++;
            }
            if ((right-left + 1) > s.size()){
                if (ss[left]!=alt1[left]){
                diff1 --;
            }
            if (ss[left]!=alt2[left]){
                diff2 --;
            }
                left++;
            }
            if ((right-left + 1)==s.size()){
                ans = min(ans,min(diff1,diff2));
            }
        }
        return ans;
    }
};