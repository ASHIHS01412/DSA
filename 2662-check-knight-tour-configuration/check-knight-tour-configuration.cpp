class Solution {
public:
    bool check(vector<vector<int>>& grid ,int n , int row, int col, int nextValue){
        int r = row , c = col;
        if(r < 0 || c < 0 || r >= n || c >= n || nextValue != grid[r][c] ){
            return false;
        }
         if(n*n-1 == grid[row][col]){
            return true;
         }
        bool ans1 = check(grid , n , row -2 , col +1 , nextValue+1);
        bool ans2 = check(grid , n , row -1 , col +2 , nextValue+1);
        bool ans3 = check(grid , n , row +1 , col +2 , nextValue+1);
        bool ans4 = check(grid , n , row +2 , col +1 , nextValue+1);
        bool ans5 = check(grid , n , row +2 , col -1 , nextValue+1);
        bool ans6 = check(grid , n , row +1 , col -2 , nextValue+1);
        bool ans7 = check(grid , n , row -1 , col -2 , nextValue+1);
        bool ans8 = check(grid , n , row -2 , col -1 , nextValue+1);
        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
        
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return check(grid ,grid.size(), 0, 0,0);

    }
};