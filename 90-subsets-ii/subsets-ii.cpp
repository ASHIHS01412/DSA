class Solution {
public:
    void calSubsets(vector<int>& nums, vector<int>& ans,
                    int i, vector<vector<int>>& allsubsets) {

        if(i == nums.size()) {
            allsubsets.push_back(ans);
            return;
        }

        // Include
        ans.push_back(nums[i]);
        calSubsets(nums, ans, i + 1, allsubsets);

        // Skip duplicates
        int idx = i + 1;

        while(idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }

        // Exclude
        ans.pop_back();
        calSubsets(nums, ans, idx, allsubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> allsubsets;
        vector<int> ans;

        calSubsets(nums, ans, 0, allsubsets);

        return allsubsets;
    }
};