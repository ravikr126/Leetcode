class Solution {
public:
    #define ll long long int
    #define md 1000000007
    ll dp[1001][1001];
    
    ll call(int idx,int k,int target,int& ans, int n,int val)
    {
        
        if(idx == n)
        {
            if(val==target)
            {
             //   ans++;
                return 1;
            }
        }
        
        if(dp[idx][val]!=-1)
        {
            return dp[idx][val];
        }
        int sum=0;
        
        for(int i=1;i<=k;i++)
        {
            if(val+i<=target)
            {
                sum=(sum+call(idx+1,k,target,ans,n,val+i))%md;
            }
                
        }
        return dp[idx][val] = sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        int ans = 0;
        int idx = 0;
        int val = 0;
        memset(dp,-1,sizeof(dp));
        int res = call(idx,k,target,ans,n,val);
        
        return res;
    }
};