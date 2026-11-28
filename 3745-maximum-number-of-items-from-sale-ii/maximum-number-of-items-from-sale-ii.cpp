class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mx = 0, minPrice = INT_MAX;

        for (auto &x : items) {
            mx = max(mx, x[0]);
            minPrice = min(minPrice, x[1]);
        }

        vector<int> freq(mx + 1, 0);

        for (auto &x : items)
            freq[x[0]]++;

        for (int i = 1; i <= mx; i++) {
            for (int j = 2 * i; j <= mx; j += i)
                freq[i] += freq[j];
        }

        // Store {price, gain}
        vector<pair<int, int>> candidates;

        for (auto &x : items) {
            int gain = freq[x[0]] - 1;

            if (gain > 0 && x[1] < 2LL * minPrice) {
                candidates.push_back({x[1], gain});
            }
        }

        sort(candidates.begin(), candidates.end());

        long long ans = 0;
        long long rem = budget;

        for (auto &x : candidates) {
            int price = x.first;
            int gain = x.second;

            long long take = min((long long)gain, rem / price);

            ans += take * 2;
            rem -= take * price;
        }

        ans += rem / minPrice;

        return (int)ans;
    }
};