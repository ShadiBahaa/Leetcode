class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<long long> prefix;
        prefix.push_back(0);
        for (int i = 0; i<nums.size(); ++i){
            prefix.push_back(prefix.back() + nums[i]);
        }
        stack<pair<long long,long long>> st;
        long long ans = 0;
        for (int i = 1; i<=nums.size(); ++i){
            long long tmp = i;
            while (!st.empty() && st.top().first > nums[i-1]){
                pair<long long, long long> val_start = st.top();
                st.pop();
                ans = max(ans,val_start.first*(prefix[i-1] - prefix[val_start.second-1]));
                cout<<ans<<endl;
                tmp = val_start.second;
            }
            st.push({nums[i-1],tmp});
        }
        while (!st.empty()){
            pair<long long, long long> val_start = st.top();
            st.pop();
            ans = max(ans,val_start.first*(prefix[nums.size()] - prefix[val_start.second-1]));
            cout<<ans<<endl;
        }
        cout<<"end"<<endl;
        return ans % (1000000000 + 7);
    }
};