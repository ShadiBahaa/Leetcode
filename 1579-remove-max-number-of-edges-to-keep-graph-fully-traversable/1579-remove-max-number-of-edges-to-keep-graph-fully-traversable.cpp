class Union_find{
    public:
    int n;
    map<int,int> parent;
    map<int,int> rank;
    Union_find(int n){
        this->n = n;
        for (int i = 1; i<=n ; ++i){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x){
        if (x == parent[x]){
            return x;
        }
        return find(parent[x]);
    }
    bool unionn(int x1, int x2){
        int p1 = find(x1);
        int p2 = find(x2);
        if (p1 == p2){
            return false;
        }
        if (rank[p1]>rank[p2]){
            rank[p1]+=rank[p2];
            parent[p2] = p1;
        }else {
            rank[p2]+=rank[p1];
            parent[p1] = p2;
        }
        n--;
        return true;
    }
    bool is_connected(void){
        return n==1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        Union_find alice(n);
        Union_find bob(n);
        for (vector<int> edge : edges){
            if (edge[0]==3){
                cnt+= (alice.unionn(edge[1],edge[2])) | (bob.unionn(edge[1],edge[2]));
            }
        }
        for (vector<int> edge: edges){
            if (edge[0]==1){
                cnt += (alice.unionn(edge[1],edge[2]));
            }else if (edge[0]==2){
                cnt += (bob.unionn(edge[1],edge[2]));
            }
        }
        if (alice.is_connected() && bob.is_connected()){
            return edges.size() - cnt;
        }
        return -1;
    }
};