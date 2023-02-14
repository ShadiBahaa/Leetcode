class Solution {
public:
    int maxProduct(string s) {
        int total = 1<<((int)s.size());
        int res = 0;
        map<int,int> mp;
        for (int mask = 1; mask<total; ++mask){
            string sub;
            for (int i = 0; i<(int)s.size(); ++i){
                if (mask&(1<<i)){
                    sub+=s[i];
                }
            }
            string tmp = sub;
            reverse(tmp.begin(),tmp.end());
            if (tmp==sub){
                mp[mask] = tmp.size();
                //cout<<mask<<" "<<tmp.size()<<endl;
            }
        }
        for (auto it = mp.begin(); it!=mp.end(); it++){
            auto it2 = it;
            it2++;
            for (; it2!=mp.end(); ++it2){
                if (((it->first) & (it2->first)) == 0){
                    res = max(res,it->second*it2->second);
                }
            }
        }
        return res;
    }
};