class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefix(arr.size()+1);
        prefix[0] = 0;
        for (int i = 1; i<=arr.size(); ++i){
            prefix[i] = prefix[i-1]^arr[i-1];
        }
        int ans = 0;
        for (int i = 0; i<arr.size(); ++i){
            for (int j = i+1; j<arr.size(); ++j){
                for (int k = j; k<arr.size(); ++k){
                    
                    if ((prefix[j]^prefix[i])==(prefix[k+1]^prefix[j])){
                        //vector<int> tmp = {i,j,k};
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};