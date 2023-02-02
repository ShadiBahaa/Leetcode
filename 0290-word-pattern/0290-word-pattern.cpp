class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        int i = 0;
        while (i<s.size()){
            int end = s.find(" ",i);
            v.push_back(s.substr(i,end-i));
            if (end==string::npos)break;
            i = end+1;
        }
        //for (string ele:v)cout<<ele<<"x"<<" ";
        //cout<<endl;
        if (v.size()!=pattern.size())return false;
        map<char,string> mp;
        map<string,char> mm;
        i = 0;
        for (string ele:v){
            if (mp.count(pattern[i]) && mp[pattern[i]]!=ele)return false;
            if (mm.count(ele) && mm[ele]!=pattern[i])return false;
            mp[pattern[i]] = ele;
            mm[ele] = pattern[i];
            i++;
        }
        return true;
    }
};