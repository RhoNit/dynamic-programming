// https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);

        // return solveMem(n, dp);
        return solveTab(n);
    }

    int solveMem(int n, vector<int> &dp) {
        // base case
        if(n == 0) return 0;

        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++) {
            int tmp = i*i;
            ans = min(ans, 1 + solveMem(n-tmp, dp));
        }

        dp[n] = ans;

        return dp[n];
    }

    int solveTab(int n) {
        vector<int> res(n+1, INT_MAX);

        // analyse base case
        res[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j*j <= n; j++) {
                int tmp = j*j;
                if(i-tmp >= 0) {
                    res[i] = min(res[i], 1 + res[i-tmp]);
                }
            }
        }

        return res[n];
    }
};