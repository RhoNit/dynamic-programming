class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();

        return solveUsingTabulation(str1, str2, m, n);
    }

    string solveUsingTabulation(string &str1, string &str2, int m, int n) {
        vector<vector<int>> res(m+1, vector<int>(n+1));

        // base case analysis
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 or j == 0) res[i][j] = 0;
            }
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(str1[i-1] == str2[j-1]) {
                    res[i][j] = 1 + res[i-1][j-1];
                }
                else {
                    res[i][j] = max(res[i-1][j], res[i][j-1]);
                }
            }
        }

        // printing the scs
        string result;
        int max_val = INT_MIN;
        int i = m, j = n;

        while(i > 0 and j > 0) {
            if(str1[i-1] == str2[j-1]) {
                result += str1[i-1];
                i--;
                j--;
            }
            else {
                if(res[i-1][j] > res[i][j-1]) {
                    result += str1[i-1];
                    i--;
                }
                else {
                    result += str2[j-1];
                    j--;
                }
            }
        }

        while(j > 0) { // when i == 0
            result += str2[j-1];
            j--;
        }

        while(i > 0) { // when j == 0
            result += str1[i-1];
            i--;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};