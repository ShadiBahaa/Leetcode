class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m*n-1;
        while (left <= right){
            int mid = left + (right-left)/2;
            int row = mid/n;
            int col = mid - n*row;
            if (matrix[row][col]==target){
                return true;
            }else if (matrix[row][col] < target){
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return false;
        }
};