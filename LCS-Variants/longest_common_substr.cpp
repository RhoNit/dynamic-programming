// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        
        return solveTabulation(s1, s2, m, n);
    }
    
    int solveTabulation(string &s1, string &s2, int m, int n) {
        vector<vector<int>> res(m+1, vector<int>(n+1));
        
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 or j == 0) res[i][j] = 0;
            }
        }
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    res[i][j] = 1 + res[i-1][j-1];
                } else {
                    res[i][j] = 0;
                }
            }
        }
        
        int maxi = INT_MIN;
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                maxi = max(res[i][j], maxi);
            }
        }
        
        return maxi;
    }
};