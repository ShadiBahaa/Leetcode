class Solution {
public:
    int numSquares(int n) {
        set<int> squares;
        for (int i = 1; i*i<=n; ++i){
            squares.insert(i*i);
        }
        queue<pair<int,int>> q;
        map<int,bool> visited;
        q.push({n,0});
        visited[n] = true;
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            if(cur.first == 0) return cur.second;
            for (int square : squares){
                if((cur.first-square >= 0) && !visited[cur.first-square]){
                    q.push({cur.first-square,cur.second+1});
                    visited[cur.first-square] = true;
                }
            }
        }
        return -1;
    }
};