class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        // return solveMemo(word1, word2, m, n, dp);
        return solveTab(word1, word2, m, n);
    }

    int solveMemo(string &word1, string &word2, int m, int n, vector<vector<int>> &dp) {
        // base case 
        if(m == 0 or n == 0) {
            if(m == 0) return n;
            if(n == 0) return m;
        }

        if(dp[m][n] != -1) return dp[m][n];

        int ans = 0;
        if(word1[m-1] == word2[n-1]) {
            dp[m][n] = solveMemo(word1, word2, m-1, n-1, dp);
        } else {
            // insertion
            int insert_ans = 1 + solveMemo(word1, word2, m, n-1, dp);
            // deletion
            int del_ans = 1 + solveMemo(word1, word2, m-1, n, dp);
            // replacement
            int rplc_ans = 1 + solveMemo(word1, word2, m-1, n-1, dp);

            dp[m][n] = min({insert_ans, del_ans, rplc_ans});
        }

        return dp[m][n];
    }

    int solveTab(string &word1, string &word2, int m, int n) {
        vector<vector<int>> res(m+1, vector<int>(n+1));

        // analyse base cases
        // suppose `word2` is empty, then  we need to delete chars from `word1`
        // the case is res[i][0]
        for(int i = 0; i <= m; i++) res[i][0] = i;

        // suppose `word1` is empty, then  we need to insert chars into `word1`
        // the case is res[0][j]
        for(int j = 0; j <= n; j++) res[0][j] = j;

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    res[i][j] = res[i-1][j-1];
                } else {
                    int insert_ans = 1 + res[i][j-1];
                    int del_ans = 1 + res[i-1][j];
                    int rplc_ans = 1 + res[i-1][j-1];

                    res[i][j] = min({insert_ans, del_ans, rplc_ans});
                }
            }
        }

        return res[m][n];
    }
};