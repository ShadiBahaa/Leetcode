class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int high = rows * cols - 1;
        while (low <= high){
            int mid = low + (high - low)/2;
            int row = mid / cols;
            int col = mid % cols;
            if(matrix[row][col] == target)return true;
            if(matrix[row][col] < target){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return false;
    }
};