class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // int buy_flag = 1;
        // int limit = 2;
        // int index = 0;

        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

        // return solveMemo(prices, index, buy_flag, limit, dp);

        return solveTab(prices);
    }

    int solveMemo(vector<int> &prices, int index, int buy_flag, int limit, vector<vector<vector<int>>> &dp) {
        // base cases
        if(index == prices.size()) return 0;
        if(limit == 0) return 0;

        if(dp[index][buy_flag][limit] != -1) return dp[index][buy_flag][limit];

        int profit = 0;
        if(buy_flag == 1) {
            int choose_to_buy = -prices[index] + solveMemo(prices, index+1, 0, limit, dp);
            int choose_to_skip_buy = 0 + solveMemo(prices, index+1, 1, limit, dp);

            profit = max(choose_to_buy, choose_to_skip_buy);
        } else {
            int choose_to_sell = prices[index] + solveMemo(prices, index+1, 1, limit-1, dp);
            int choose_to_skip_sell = 0 + solveMemo(prices, index+1, 0, limit, dp);

            profit = max(choose_to_sell, choose_to_skip_sell);
        }

        dp[index][buy_flag][limit] = profit;

        return dp[index][buy_flag][limit];
    }

    int solveTab(vector<int> &prices) {
        int n = prices.size();

        vector<vector<vector<int>>> res(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        // analyse the base cases
        // when `limit` becomes 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                res[i][j][0] = 0;
            }
        }

        // when `index` becomes 0
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                res[0][j][k] = 0;
            }
        }

        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < 2; j++) {
                for(int k = 1; k < 3; k++) {
                    int profit = 0;

                    if(j == 1) {
                        int choose_to_buy = -prices[i] + res[i+1][0][k];
                        int choose_to_skip_buy = 0 + res[i+1][1][k];

                        profit = max(choose_to_buy, choose_to_skip_buy);
                    } else {
                        int choose_to_sell = prices[i] + res[i+1][1][k-1];
                        int choose_to_skip_sell = 0 + res[i+1][0][k];

                        profit = max(choose_to_sell, choose_to_skip_sell);
                    }

                    res[i][j][k] = profit;
                }
            }
        }

        return res[0][1][2];
    }
};