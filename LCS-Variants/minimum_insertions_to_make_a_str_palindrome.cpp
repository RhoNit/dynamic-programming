class Solution {
public:
    int minInsertions(string s) {
        int m = s.size();
        string rev_str = s;
        reverse(s.begin(), s.end());

        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));

        int len_lps = solveByMemoization(s, rev_str, m, m, dp);

        return m-len_lps;
    }

    int solveByMemoization(string &str, string &rev_str, int m, int n, vector<vector<int>> &dp) {
        // base case
        if(m == 0 or n == 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        if(str[m-1] == rev_str[n-1]) {
            dp[m][n] = solveByMemoization(str, rev_str, m-1, n-1, dp) + 1;
        } else {
            dp[m][n] = max(solveByMemoization(str, rev_str, m, n-1, dp), solveByMemoization(str, rev_str, m-1, n, dp));
        }

        return dp[m][n];
    }
};
