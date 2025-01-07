// https://www.naukri.com/code360/problems/rod-cutting-problem_800284

#include<bits/stdc++.h>

int solve(int n, int w, vector<int> &length, vector<int> &price, vector<vector<int>> &dp) {
    // base case
    if(n == 0 or w == 0) return 0;

    if(dp[n][w] != -1) return dp[n][w];

    if(length[n-1] <= w) {
        int picked = price[n-1] + solve(n, w-length[n-1], length, price, dp);
        int not_picked = solve(n-1, w, length, price, dp);

        dp[n][w] = max(picked, not_picked);
    }
    else dp[n][w] = solve(n-1, w, length, price, dp);

    return dp[n][w];
}

int cutRod(vector<int> &price, int n) {
	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

	vector<int> length;
	for(int i = 1; i <= n; i++) length.push_back(i);

	return solve(n, n, length, price, dp);
}
