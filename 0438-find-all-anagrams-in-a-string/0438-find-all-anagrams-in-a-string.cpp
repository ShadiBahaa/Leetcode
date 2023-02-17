class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size()>s.size())return {};
        map<char,int> mpp;
        map<char,int> mps;
        for (int i = 0; i<p.size(); ++i){
            mpp[p[i]]++;
            mps[s[i]]++;
        }
        vector<int> v;
        if (mpp==mps){
            v.push_back(0);
        }
        int l = 0;
        for (int r = p.size(); r<s.size(); ++r){
            mps[s[l]]--;
            mps[s[r]]++;
            if (mps[s[l]]==0)mps.erase(s[l]);
            l++;
            if (mps==mpp){
                v.push_back(l);
            }
        }
        return v;
    }
};