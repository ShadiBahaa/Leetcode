class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows==1)return {{1}};
        if (numRows==2)return {{1},{1,1}};
        vector<vector<int>> v(numRows);
        v[0].push_back(1);
        v[1].push_back(1);
        v[1].push_back(1);
        for (int i = 2; i<numRows; ++i){
            v[i].push_back(1);
            for (int j = 0; j<=i-2; ++j){
                v[i].push_back(v[i-1][j]+v[i-1][j+1]);
            }
            v[i].push_back(1);
        }
        return v;
    }
};