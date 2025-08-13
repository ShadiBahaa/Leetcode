class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> position(n);
        for (int i = 0; i < n; ++i) {
            position[row[i]] = i;
        }

        int swaps = 0;
        for (int i = 0; i < n; i += 2) {
            int first = row[i];
            int partner = first ^ 1; 
            if (row[i+1] != partner) {
                swaps++;
                int partnerPos = position[partner];
                
                swap(row[i+1], row[partnerPos]);
                
                position[row[partnerPos]] = partnerPos;
                position[row[i+1]] = i + 1;
            }
        }
        return swaps;
    }
};
