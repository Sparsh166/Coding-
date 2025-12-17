class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = LLONG_MIN / 2;

        // dp[t][0] = no position
        // dp[t][1] = holding long
        // dp[t][2] = holding short
        vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG));
        dp[0][0] = 0;

        for (int price : prices) {
            auto new_dp = dp;

            for (int t = 0; t <= k; t++) {
                // Stay idle
                new_dp[t][0] = max(new_dp[t][0], dp[t][0]);

                // Enter long
                if (t < k)
                    new_dp[t][1] = max(new_dp[t][1], dp[t][0] - price);

                // Exit long
                if (t < k)
                    new_dp[t + 1][0] = max(new_dp[t + 1][0], dp[t][1] + price);

                // Enter short
                if (t < k)
                    new_dp[t][2] = max(new_dp[t][2], dp[t][0] + price);

                // Exit short
                if (t < k)
                    new_dp[t + 1][0] = max(new_dp[t + 1][0], dp[t][2] - price);
            }
            dp = new_dp;
        }

        long long ans = 0;
        for (int t = 0; t <= k; t++)
            ans = max(ans, dp[t][0]);

        return ans;
    }
};
