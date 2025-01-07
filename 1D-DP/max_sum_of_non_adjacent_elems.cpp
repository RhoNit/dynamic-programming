// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>

int solveTabulation(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, 0);

    // base case analysis
    res[0] = nums[0];
    res[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++) {
        int incl = res[i-2] + nums[i];
        int excl = res[i-1];

        res[i] = max(incl, excl);
    }

    return res[n-1];
}

int solveTopDown(vector<int>& nums, int n, vector<int> &dp) {
    // base case
    if(n < 0) return 0;
    if(n == 0) return nums[0];

    if(dp[n] != -1) return dp[n];

    int incl = solveTopDown(nums, n-2, dp) + nums[n];
    int excl = solveTopDown(nums, n-1, dp);

    dp[n] = max(incl, excl);

    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // int n = nums.size();
    // vector<int> dp(n, -1);
    // return solveTopDown(nums, n-1, dp);

    return solveTabulation(nums);
}