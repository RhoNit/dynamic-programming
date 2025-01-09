class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.size();
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());

        return getLCSLen(s, s_rev, m, m);
    }

    int getLCSLen(string &s, string &s_rev, int m, int n) {
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        // return solveTopDown(s, s_rev, m, n, dp);

        return solveTabulation(s, s_rev, m, n);
    }

    int solveTopDown(string &s, string &s_rev, int m, int n, vector<vector<int>> &dp) {
        // base case
        if(m == 0 or n == 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        if(s[m-1] == s_rev[n-1]) {
            dp[m][n] = solveTopDown(s, s_rev, m-1, n-1, dp) + 1;
        } else {
            dp[m][n] = max(solveTopDown(s, s_rev, m, n-1, dp), solveTopDown(s, s_rev, m-1, n, dp));
        }

        return dp[m][n];
    }

    int solveTabulation(string &s, string &s_rev, int m, int n) {
        vector<vector<int>> res(m+1, vector<int>(n+1));
        // base case analysis
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 or j == 0) res[i][j] = 0;
            }
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == s_rev[j-1]) {
                    res[i][j] = 1 + res[i-1][j-1];
                } else {
                    res[i][j] = max(res[i][j-1], res[i-1][j]);
                }
            }
        }

        return res[m][n];
    }
};