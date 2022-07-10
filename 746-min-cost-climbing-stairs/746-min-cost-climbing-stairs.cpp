class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
         vector<int> dp(n+1,-1);
        
         if(n<=1)return 0;
             
         dp[0] = 0;
	     dp[1] = 0;

	     for(int j=2;j<=n;j++){
		     dp[j] = min(cost[j-1] + dp[j-1], cost[j-2] + dp[j-2]);
	     }
	  return dp[n]; 
    }
};