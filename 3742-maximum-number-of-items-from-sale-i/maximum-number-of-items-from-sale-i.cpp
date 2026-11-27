class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();
        int minPrice = INT_MAX;

        vector<int> dp(budget + 1, 0);

        for (auto &item : items) {
            int factor = item[0];
            int price = item[1];

            minPrice = min(minPrice, price);

            int cnt = 0;

            for (auto &other : items) {
                if (other[0] % factor == 0) {
                    cnt++;
                }
            }

            // 0/1 Knapsack
            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j], dp[j - price] + cnt);
            }
        }

        int ans = 0;

        for (int i = 0; i <= budget; i++) {
            int extra = (budget - i) / minPrice;
            ans = max(ans, dp[i] + extra);
        }

        return ans;
    }
};