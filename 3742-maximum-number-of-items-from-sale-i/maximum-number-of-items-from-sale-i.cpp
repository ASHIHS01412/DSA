class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();
        int minPrice = INT_MAX;

        vector<vector<int>> dp(
            n + 1, vector<int>(budget + 1, 0)
        );

        for (int i = 0; i < n; i++) {

            int factor = items[i][0];
            int price = items[i][1];

            minPrice = min(minPrice, price);

            int cnt = 0;

            for (auto &item : items) {
                if (item[0] % factor == 0) {
                    cnt++;
                }
            }

            for (int j = 0; j <= budget; j++) {

                // Skip this item type
                dp[i + 1][j] = dp[i][j];

                // Buy its first copy
                if (j >= price) {
                    dp[i + 1][j] = max(
                        dp[i + 1][j],
                        dp[i][j - price] + cnt
                    );
                }
            }
        }

        int ans = 0;

        for (int i = 0; i <= budget; i++) {
            ans = max(
                ans,
                dp[n][i] + (budget - i) / minPrice
            );
        }

        return ans;
    }
};