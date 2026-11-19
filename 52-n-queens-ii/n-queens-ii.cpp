class Solution {
public:
    int count = 0;

    vector<bool> col, diag1, diag2;

    void solve(int row, int n) {

        if(row == n) {
            count++;
            return;
        }

        for(int c = 0; c < n; c++) {

            int d1 = row - c + n - 1;
            int d2 = row + c;

            if(col[c] || diag1[d1] || diag2[d2])
                continue;

            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            solve(row + 1, n);

            col[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }

    int totalNQueens(int n) {

        col.resize(n, false);
        diag1.resize(2*n - 1, false);
        diag2.resize(2*n - 1, false);

        solve(0, n);

        return count;
    }
};