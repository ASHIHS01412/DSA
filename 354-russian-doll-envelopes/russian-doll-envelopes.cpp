
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort width ascending, height descending
        sort(envelopes.begin(), envelopes.end(),
            [](const vector<int>& a, const vector<int>& b) {

                if(a[0] == b[0]) {
                    return a[1] > b[1];
                }

                return a[0] < b[0];
            });

        vector<int> lis;

        for(auto& e : envelopes) {
            int height = e[1];
            auto it = lower_bound(lis.begin(), lis.end(), height);
            if(it == lis.end()) {
                lis.push_back(height);
            }
            else {
                *it = height;
            }
        }
        return lis.size();
    }
};
