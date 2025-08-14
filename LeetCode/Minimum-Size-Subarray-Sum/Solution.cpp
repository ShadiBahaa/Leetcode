class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int n = nums.length;
        if (n == 0) {
            return 0;
        }

        int ans = Integer.MAX_VALUE;

        int[] sums = new int[n + 1]; 
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= n; i++) {
            int target = s + sums[i - 1];
            int bound = Arrays.binarySearch(sums, target);
            
            if (bound < 0) {
                bound = -bound - 1;
            }

            if (bound <= n) {
                ans = Math.min(ans, bound - (i - 1));
            }
        }

        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}