class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        map<int,pair<int,int>> dp;
        int len = 0;
        int count = 0;
        for (int i = nums.size()-1; i>=0; --i){
            int tmp_len = 1, tmp_count = 1;
            for (int j = i + 1; j<nums.size(); ++j){
                pair<int,int> len_count_pair = dp[j];
                if (nums[j] > nums[i]){
                    if (len_count_pair.first + 1 > tmp_len ){
                        tmp_len = len_count_pair.first +1;
                        tmp_count = len_count_pair.second;
                    }else if (len_count_pair.first + 1 == tmp_len){
                        tmp_count += len_count_pair.second;
                    }
                }
            }
            dp[i] = {tmp_len,tmp_count};
            if (tmp_len > len){
                len = tmp_len;
                count = tmp_count;
            }else if (tmp_len == len){
                count += tmp_count;
            }
        }
        return count;
    }
};