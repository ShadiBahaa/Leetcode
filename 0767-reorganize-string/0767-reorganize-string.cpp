class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        for (char c : s){
            mp[c]++;
        }
        string ans;
        priority_queue<pair<int,char>> pq;
        for (pair<char,int> p : mp){
            pq.push({p.second,p.first});
        }
        pair<int,char> prev;
        prev.first = -1;
        while (pq.size() || prev.first!=-1){
            if (prev.first != -1 && pq.empty()){
                return "";
            }
            pair<int,char> p = pq.top();
            pq.pop();
            p.first--;
            ans+=p.second;
            if (prev.first != -1){
                pq.push(prev);
                prev.first = -1;
            }
            if (p.first != 0){
                prev = p;
            }
            
        }
        return ans;
    }
};