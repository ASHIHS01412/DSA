class Solution {
public:
    void calSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allsubsets) {

        if(i == nums.size()) {
            allsubsets.push_back({ans});
            return;
        }

        // Include
        ans.push_back(nums[i]);
        calSubsets(nums, ans, i + 1, allsubsets);

        // Exclude
        ans.pop_back();
        calSubsets(nums, ans, i + 1, allsubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> allsubsets;
        vector<int> ans;

        calSubsets(nums, ans, 0, allsubsets);

        return allsubsets;
    }
};