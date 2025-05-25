class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;
        set<string> s;
        for(string str : deadends){
            s.insert(str);
        }
        map<string,bool> visited;
        q.push({"0000",0});
        visited["0000"] = true;
        while(!q.empty()){
            pair<string,int> cur = q.front();
            q.pop();
            if(cur.first == target)return cur.second;
            if(s.count(cur.first))continue;
            for(int i = 0; i<4; ++i){
                string ss = cur.first;
                ss[i] = (((cur.first[i] - '0') - 1 + 10)%10) + '0';
                pair<string,int> new_p = {ss,cur.second+1};
                cout<<ss<<endl;
                if(!visited[ss]){
                    q.push(new_p);
                    visited[ss] = true;
                }
                ss[i] = (((cur.first[i] - '0') + 1)%10) + '0';
                new_p = {ss,cur.second+1};
                cout<<ss<<endl;
                if(!visited[ss]){
                    q.push(new_p);
                    visited[ss] = true;
                }
            }
        }
        return -1;
    }
};