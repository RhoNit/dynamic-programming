// https://www.naukri.com/code360/problems/house-robber_839733

#include <bits/stdc++.h>

long long int solveTopDown(vector<int>& valueInHouse, int n, vector<long long int> &dp) {
    // base case
    if(n < 0) return 0;
    if(n == 0) return valueInHouse[0];

    if(dp[n] != -1) return dp[n];

    long long int incl = solveTopDown(valueInHouse, n-2, dp) + valueInHouse[n];
    long long int excl = solveTopDown(valueInHouse, n-1, dp);

    dp[n] = max(incl, excl);

    return dp[n];
}

long long int houseRobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];

    vector<int> left, right;

    for(int i = 0; i < n; i++) {
        if(i != n-1) left.push_back(valueInHouse[i]);
        if(i != 0) right.push_back(valueInHouse[i]);
    }

    vector<long long int> dp_left(left.size(), -1);
    vector<long long int> dp_right(right.size(), -1);

    long long int ans1 = solveTopDown(left, left.size()-1, dp_left);
    long long int ans2 = solveTopDown(right, right.size()-1, dp_right);

    return max(ans1, ans2);
}