class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> v;
        v.push_back(-1);
        int maxi = -1;
        for (int i = (int)arr.size()-1; i>=1; --i){
            maxi = max(maxi,arr[i]);
            v.push_back(maxi);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};