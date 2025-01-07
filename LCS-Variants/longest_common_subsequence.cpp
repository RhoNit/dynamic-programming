class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        // return solveTopDown(text1, text2, m, n, dp);

        return solveTabulation(text1, text2, m, n);
    }

    int solveTopDown(string &s1, string &s2, int m, int n, vector<vector<int>> &dp) {
        // base case
        if(m == 0 or n == 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        if(s1[m-1] == s2[n-1]) {
            dp[m][n] = solveTopDown(s1, s2, m-1, n-1, dp) + 1;
        } else {
            dp[m][n] = max(solveTopDown(s1, s2, m-1, n, dp), solveTopDown(s1, s2, m, n-1, dp));
        }

        return dp[m][n];
    }

    int solveTabulation(string text1, string text2, int m, int n) {
        vector<vector<int>> res(m+1, vector<int>(n+1));

        // base case analysis
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 or j == 0) res[i][j] = 0;
            }
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i-1] == text2[j-1]) {
                    res[i][j] = res[i-1][j-1] + 1;
                } else {
                    res[i][j] = max(res[i-1][j], res[i][j-1]);
                }
            }
        }

        return res[m][n];
    }
};