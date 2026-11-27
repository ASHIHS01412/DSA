class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        const int MAXF = 1500;

        vector<int> freq(MAXF + 1, 0);
        vector<int> cnt(MAXF + 1, 0);

        int minPrice = INT_MAX;

        for (auto &item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        // Precompute divisibility counts
        for (int f = 1; f <= MAXF; f++) {
            for (int j = f; j <= MAXF; j += f) {
                cnt[f] += freq[j];
            }
        }

        vector<int> dp(budget + 1, 0);

        for (auto &item : items) {

            int factor = item[0];
            int price = item[1];

            for (int j = budget; j >= price; j--) {
                dp[j] = max(
                    dp[j],
                    dp[j - price] + cnt[factor]
                );
            }
        }

        int ans = 0;

        for (int i = 0; i <= budget; i++) {
            ans = max(
                ans,
                dp[i] + (budget - i) / minPrice
            );
        }

        return ans;
    }
};