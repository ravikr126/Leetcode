class Solution {
public:
   // Time Complexity : O(n^3)

//Space Complexity : O(n^2)

    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(nums, 1, n-1, dp);
    }
    
    int solve(vector<int>& nums, int l, int r, vector<vector<int>> &dp){
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        
        int ans = 0; 
        
        for(int i = l; i<r; i++){
            int temp = solve(nums, l, i, dp) + solve(nums, i+1, r, dp) + nums[l-1]*nums[i]*nums[r];
            ans = max(ans, temp);
        }
        return dp[l][r] = ans;
    } 
};