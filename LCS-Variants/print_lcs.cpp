// https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383

#include<bits/stdc++.h>

string findLCS(int n, int m,string &s1, string &s2){
	string result;
	vector<vector<int>> res(n+1, vector<int>(m+1));
	
	// base case analysis
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			if(i == 0 or j == 0) res[i][j] = 0;
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s1[i-1] == s2[j-1]) {
				res[i][j] = 1 + res[i-1][j-1];
			} else {
				res[i][j] = max(res[i][j-1], res[i-1][j]);
			}
		}
	}

	// printing logic
	int i = n, j = m;
	while(i > 0 and j > 0) {
		if(s1[i-1] == s2[j-1]) {
			result += s1[i-1];
			i--;
			j--;
		}
		else {
			if(res[i][j-1] > res[i-1][j]) j--;
			else i--;
		}
	}

	reverse(result.begin(), result.end());

	return result;		
}