class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int count = 0;
        int a , b;
        int sum = ((n*n)*((n*n) + 1))/2;

        for(int i =0; i < n; i++){
            for(int j = 0; j < n ; j++){
                count = count + grid[i][j];
                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                   
                }
                s.insert(grid[i][j]);

            }
        }
        b = sum -(count - a);
        ans.push_back(b);
       

        return ans;
    }
};