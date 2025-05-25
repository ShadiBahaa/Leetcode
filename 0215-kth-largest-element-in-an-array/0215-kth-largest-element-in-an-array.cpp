class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int num : nums){
            pq.push(num);
        }
        int val = -1;
        while(k--){
            val = pq.top();
            pq.pop();
        }
        return val;
    }
};