// https://www.naukri.com/code360/problems/cut-into-segments_1214651

#include<bits/stdc++.h>

int solveTabulation(int x, int y, int z, int n) {
	vector<int> res(n+1, INT_MIN);
	// analyse base cases
	res[0] = 0;

	for(int i = 1; i <= n; i++) {
		if(i-x >= 0) res[i] = max(res[i], res[i-x] + 1);
		if(i-y >= 0) res[i] = max(res[i], res[i-y] + 1);
		if(i-z >= 0) res[i] = max(res[i], res[i-z] + 1);
	}

	return res[n] < 0 ? 0 : res[n];
}

int solveTopDown(int n, int x, int y, int z, vector<int> &dp) {
	// base case
	if(n == 0) return 0;
	if(n < 0) return INT_MIN;

	if(dp[n] != -1) return dp[n];
	
	int ans1 = solveTopDown(n-x, x, y, z, dp) + 1;
	int ans2 = solveTopDown(n-y, x, y, z, dp) + 1;
	int ans3 = solveTopDown(n-z, x, y, z, dp) + 1;

	dp[n] = max(ans1, max(ans2, ans3));

	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// vector<int> dp(n+1, -1);

	// int res = solveTopDown(n, x, y, z, dp);
	// return res < 0 ? 0 : res;

	return solveTabulation(x, y, z, n);
}