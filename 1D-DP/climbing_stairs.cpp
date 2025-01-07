class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);

        // return solveTopDown(n, dp);
        if(n == 1) return 1;
        return solveTabulation(n);
    }

    int solveTopDown(int n, vector<int> &dp) {
        // base case 
        if(n == 1) return 1;
        if(n == 2) return 2;

        if(dp[n] != -1) return dp[n];

        dp[n] = solveTopDown(n-1, dp) + solveTopDown(n-2, dp);

        return dp[n];
    }

    int solveTabulation(int n) {
        vector<int> res(n+1, 0);

        // analyse base cases
        res[1] = 1;
        res[2] = 2;

        for(int i = 3; i <= n; i++) {
            res[i] = res[i-2] + res[i-1];
        }

        return res[n];
    }
};