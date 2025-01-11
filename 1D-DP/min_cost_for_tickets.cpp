// https://www.naukri.com/code360/problems/minimum-coins_2180776

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> set;
        for(int day: days) set.insert(day);

        int last_day = days[days.size()-1];
        vector<int> dp(last_day + 30, -1);

        return solve(days, costs, days[0], set, dp);
    }

    int solve(vector<int>& days, vector<int>& costs, int curr_day, unordered_set<int> &set, vector<int> &dp) {
        // base case
        if(curr_day > days[days.size()-1]) return 0;

        if(dp[curr_day] != -1) return dp[curr_day];

        if(set.find(curr_day) == set.end()) {
            dp[curr_day] = solve(days, costs, curr_day + 1, set, dp);
            return dp[curr_day];
        }

        int choice1 = costs[0] + solve(days, costs, curr_day + 1, set, dp);
        int choice2 = costs[1] + solve(days, costs, curr_day + 7, set, dp);
        int choice3 = costs[2] + solve(days, costs, curr_day + 30, set, dp);

        dp[curr_day] = min(choice1, min(choice2, choice3));

        return dp[curr_day];
    }
};