
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();
        int srow = 0, erow = m - 1;
        int scol = 0, ecol = n - 1;

        vector<int> ans;
        while(srow <= erow && scol <= ecol) {
            // Top
            for(int i = scol; i <= ecol; i++) {
                ans.push_back(matrix[srow][i]);
            }
            srow++;
            // Right
            for(int i = srow; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }
            ecol--;
            // Bottom
            if(srow <= erow) {
                for(int i = ecol; i >= scol; i--) {
                    ans.push_back(matrix[erow][i]);
                }
                erow--;
            }
            // Left
            if(scol <= ecol) {
                for(int i = erow; i >= srow; i--) {
                    ans.push_back(matrix[i][scol]);
                }
                scol++;
            }
        }
        return ans;
    }
};
