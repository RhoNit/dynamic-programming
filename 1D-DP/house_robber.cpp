class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 0) return 0;

        // vector<int> dp(n, -1);

        // return solveTopDown(nums, n-1, dp);

        return solveTabulation(nums);
    }

    int solveTabulation(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        // analyse base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            int incl = dp[i-2] + nums[i];
            int excl = dp[i-1];

            dp[i] = max(incl, excl);
        }

        return dp[n-1];
    }

    int solveTopDown(vector<int> &nums, int n, vector<int> &dp) {
        // base case
        if(n < 0) return 0;
        if(n == 0) return nums[0];

        if(dp[n] != -1) return dp[n];

        int incl = solveTopDown(nums, n-2, dp) + nums[n];
        int excl = solveTopDown(nums, n-1, dp);

        dp[n] = max(incl, excl);

        return dp[n];
    }
};