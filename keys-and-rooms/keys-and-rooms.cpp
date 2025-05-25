class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        map<int,bool> vis;
        vis[0] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int room : rooms[cur]){
                if(!vis[room]){
                    q.push(room);
                    vis[room] = true;
                }
            }
        }
        for (int i = 0; i<rooms.size(); ++i){
            if(!vis[i])return false;
        }
        return true;
    }
};