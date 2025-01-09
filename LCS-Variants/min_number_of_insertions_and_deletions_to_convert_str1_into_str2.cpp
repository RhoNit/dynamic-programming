// https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

class Solution {

  public:
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int m = s1.size(), n = s2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int len_lcs = solveUsingMemoization(s1, s2, m, n, dp);
        
        int del_cnt = m - len_lcs;
        int ins_cnt = n - len_lcs;
        
        return del_cnt + ins_cnt;
    }
    
    int solveUsingMemoization(string &s1, string &s2, int m, int n, vector<vector<int>> &dp) {
        // base case
        if(m == 0 or n == 0) return 0;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        // main logic
        if(s1[m-1] == s2[n-1]) {
            dp[m][n] = solveUsingMemoization(s1, s2, m-1, n-1, dp) + 1;
        } else {
            dp[m][n] = max(solveUsingMemoization(s1, s2, m-1, n, dp), solveUsingMemoization(s1, s2, m, n-1, dp));
        }
        
        return dp[m][n];
    }
};