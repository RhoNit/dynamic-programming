// https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

class Solution {
  public:
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        int m = s.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        
        // return solveUsingMemoization(s, s, m, m, dp);
        return solveByTabulation(s, s, m, m);
    }
    
    int solveUsingMemoization(string &s1, string &s2, int m, int n, vector<vector<int>> &dp) {
        // base case
        if(m == 0 or n == 0) return 0;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        if(s1[m-1] == s2[n-1] and m != n) {
            dp[m][n] = 1 + solveUsingMemoization(s1, s2, m-1, n-1, dp);
        } else {
            dp[m][n] = max(solveUsingMemoization(s1, s2, m, n-1, dp), solveUsingMemoization(s1, s2, m-1, n, dp));
        }
        
        return dp[m][n];
    }
    
    int solveByTabulation(string &s1, string &s2, int m, int n) {
    	vector<vector<int>> res(m+1, vector<int>(n+1));
    	
    	// analyse base cases
    	for(int i = 0; i <= m; i++) {
    		for(int j = 0; j <= n; j++) {
    			if(i == 0 or j == 0) res[i][j] = 0;
    		}
    	}
    	
    	for(int i = 1; i <= m; i++) {
    		for(int j = 1; j <= n; j++) {
    			if(s1[i-1] == s2[j-1] and i != j) {
    				res[i][j] = 1 + res[i-1][j-1];
    			} else {
    				res[i][j] = max(res[i-1][j], res[i][j-1]);
    			}
    		}
    	}
    	
    	return res[m][n];
    }
};