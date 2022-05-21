class Solution {
public:
    void helper(vector<int>&coins,int amount ,vector<int>&dp ){
    dp[0]=0;
    for(int i=1;i<10001;i++) {
        for(int j=0;j<coins.size();j++) {
            if(coins[j]<=i){
                if(dp[i-coins[j]]!=INT_MAX)
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                            }
                    }
            }
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(10001,INT_MAX);
        sort(begin(coins),end(coins));
        
        helper(coins,amount,dp);
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};