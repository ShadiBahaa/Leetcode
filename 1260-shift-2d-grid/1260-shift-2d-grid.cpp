class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        deque<int> tmp1;
        for (vector<int> v : grid){
            for (int i : v){
                tmp1.push_back(i);
            }
        }
        while (k--){
            int x = tmp1.back();
            tmp1.pop_back();
            tmp1.push_front(x);
        }
        int cnt = 0;
        for (int i = 0; i<grid.size(); i++){
            for (int j = 0; j<grid[i].size(); ++j){
                grid[i][j] = tmp1[cnt];
                cnt++;
            }
        }
        return grid;
    }
};