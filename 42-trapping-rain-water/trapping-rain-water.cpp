class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>Lmax(n , 0 );
        vector<int>Rmax(n , 0 );
        Lmax[0] = height[0];
        Rmax[n-1] = height[n-1];
        int ans = 0 ; 

        for(int i = 1; i < n ; i++){
            Lmax[i] = max(Lmax[i-1] , height[i]);
        }
        for(int i = n - 2; i >= 0 ; i--){
            Rmax[i] = max(Rmax[i+1] , height[i]);
        }
        for(int i = 0; i < n; i++){
            ans += min(Lmax[i], Rmax[i]) - height[i];
        }
        return ans;
    }
};