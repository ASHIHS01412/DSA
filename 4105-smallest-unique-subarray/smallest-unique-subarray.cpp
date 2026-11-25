class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        const long long MOD1 = 1000000007;
        const long long MOD2 = 1000000009;
        const long long BASE = 911382323;

        int n = nums.size();

        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);

        for(int i = 0; i < n; i++) {
            p1[i + 1] = p1[i] * BASE % MOD1;
            p2[i + 1] = p2[i] * BASE % MOD2;

            h1[i + 1] = (h1[i] * BASE + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i]) % MOD2;
        }

        auto check = [&](int len) {
            unordered_map<unsigned long long, int> mp;
            mp.reserve(n * 2);

            for(int i = 0; i + len <= n; i++) {
                int j = i + len;

                long long x = (h1[j] -
                    h1[i] * p1[len] % MOD1 + MOD1) % MOD1;

                long long y = (h2[j] -
                    h2[i] * p2[len] % MOD2 + MOD2) % MOD2;

                unsigned long long key =
                    (unsigned long long)x * MOD2 + y;

                mp[key]++;
            }

            for(auto &it : mp) {
                if(it.second == 1)
                    return true;
            }

            return false;
        };

        int l = 1, r = n;
        int ans = n;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};