class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        unordered_map<int, int> mp;
        int count = 0;
        int n = nums1.size();

        // Store all possible sums of nums1 and nums2
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[nums1[i] + nums2[j]]++;
            }
        }

        // Find complementary sums
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                int sum = -(nums3[i] + nums4[j]);

                count += mp[sum];
            }
        }

        return count;
    }
};