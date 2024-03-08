class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<string,int> mp;
        mp["I"] = 1;
        mp["V"] = 5;
        mp["X"] = 10;
        mp["L"] = 50;
        mp["C"] = 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4;
        mp["IX"] = 9;
        mp["XL"] = 40;
        mp["XC"] = 90;
        mp["CD"] = 400;
        mp["CM"] = 900;
        
        for (int i = 0; i<s.size(); ++i){
            bool ok = false;
            if (i<=((int)s.size()-2)){
                string x;
                x+=s[i];
                x+=s[i+1];
                if (mp.count(x))
                {ans += mp[x];i++;ok = true;}
            }
            if (!ok){
                string x; 
                    x+=s[i];
                ans += mp[x];
            }
        }
        return ans;
    }
};