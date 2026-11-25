class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        for(int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }

        // Build suffix array using doubling
        for(int k = 1; ; k *= 2) {

            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if(rank[a] != rank[b])
                    return rank[a] < rank[b];

                int x = (a + k < n) ? rank[a + k] : -1;
                int y = (b + k < n) ? rank[b + k] : -1;

                return x < y;
            });

            temp[sa[0]] = 0;

            for(int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                bool different =
                    rank[a] != rank[b] ||
                    (a + k < n ? rank[a + k] : -1) !=
                    (b + k < n ? rank[b + k] : -1);

                temp[b] = temp[a] + different;
            }

            rank.swap(temp);

            if(rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build inverse suffix array
        vector<int> pos(n);

        for(int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        // Kasai LCP algorithm
        vector<int> lcp(n, 0);
        int h = 0;

        for(int i = 0; i < n; i++) {
            int r = pos[i];

            if(r == n - 1) {
                h = 0;
                continue;
            }

            int j = sa[r + 1];

            while(i + h < n && j + h < n &&
                  nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if(h > 0)
                h--;
        }

        // Find smallest unique subarray
        int ans = n;

        for(int r = 0; r < n; r++) {
            int left = (r > 0) ? lcp[r - 1] : 0;
            int right = (r < n - 1) ? lcp[r] : 0;

            int maxLCP = max(left, right);

            int required = maxLCP + 1;

            if(required <= n - sa[r]) {
                ans = min(ans, required);
            }
        }

        return ans;
    }
};