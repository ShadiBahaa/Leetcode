class Solution {
public:
    string s1,s2;
    map<pair<int,int>,int> mp;
    int m(int i, int j){
        return s1[i]!=s2[j];
    }
    int cost(int i, int j){
        if (i==-1 && j==-1)return 0;
        if (i==-1)return j+1;
        if (j==-1)return i+1;
        if (mp.count({i,j}))return mp[{i,j}];
        return mp[{i,j}] = min(cost(i,j-1)+1,min(cost(i-1,j)+1,cost(i-1,j-1)+m(i,j)));
    }
    int minDistance(string word1, string word2) {
        s1 = word1;
        s2 = word2;
        return cost(word1.size()-1,word2.size()-1);
    }
};