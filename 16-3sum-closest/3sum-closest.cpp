class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans =  nums[0]+ nums[1]+ nums[2]  ;

        for(int i = 0; i < nums.size()-2; i++){
            int y = i + 1;
            int z = nums.size()-1;
            while( y < z){
               int x = nums[i]+ nums[y]+ nums[z] ;
                
                if(abs(ans - target)  > abs(x - target)){
                    ans = x;
                }
                if(x > target){
                    z--;
                }
                else if(x < target){
                    y++;

                }
                else{
                    return x;
                }

            }
        }
        return ans;
    }
};