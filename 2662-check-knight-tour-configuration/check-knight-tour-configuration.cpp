class Solution {
public:
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    bool check(vector<vector<int>>& grid, int n,
               int row, int col, int nextValue) {

        if (nextValue == n * n) {
            return true;
        }

        for (int i = 0; i < 8; i++) {
            int r = row + dx[i];
            int c = col + dy[i];

            if (r >= 0 && c >= 0 && r < n && c < n &&
                grid[r][c] == nextValue) {

                return check(grid, n, r, c, nextValue + 1);
            }
        }

        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0) return false;
        return check(grid, n, 0, 0, 1);
    }
};