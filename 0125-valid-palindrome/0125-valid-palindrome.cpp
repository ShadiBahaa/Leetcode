class Solution {
public:
    string tmp;
    bool notAlpha(int ind){
        return !(tmp[ind]>='A' && tmp[ind]<='Z') && !(tmp[ind]>='a' && tmp[ind]<='z') && !(tmp[ind]>='0' && tmp[ind]<='9');
    }
    bool pal(int start, int end){
        while(notAlpha(start) && start<=end){
            start++;
            }
        while(notAlpha(end) && end>=start){
            end--;
            }
        if(start >= end)return true;
        if(tolower(tmp[start])==tolower(tmp[end])){
            return pal(start+1,end-1);
        }
        return false;
    }
    bool isPalindrome(string s) {
        tmp = s;
        return pal(0,s.size()-1);
    }
};