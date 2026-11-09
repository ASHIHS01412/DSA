
class Solution {
public:
    void solve(vector<int>& candidates, int target,
               int index, vector<int>& ans,
               vector<vector<int>>& result) {

        if(target == 0) {
            result.push_back(ans);
            return;
        }

        if(index == candidates.size() || target < 0) {
            return;
        }

        // Include current element
        ans.push_back(candidates[index]);

        solve(candidates, target - candidates[index],
              index, ans, result);

        // Backtrack
        ans.pop_back();

        // Exclude current element
        solve(candidates, target, index + 1,
              ans, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> result;
        vector<int> ans;

        solve(candidates, target, 0, ans, result);

        return result;
    }
};
