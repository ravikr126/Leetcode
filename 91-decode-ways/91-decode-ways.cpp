class Solution {
public:
    int f(int i,string &s,vector<int> &dp)
    {
      if(i==s.size()) return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        if(s[i]=='0') return 0;
        
        int count=0;
        count+=f(i+1,s,dp);
        
        if(i+1<s.size() && ( s[i]=='1' || (s[i]=='2' && s[i+1]<='6') ) )
            count+=f(i+2,s,dp);
        
        return dp[i]=count;
    }
    
    int numDecodings(string s) {
        
        vector<int> dp(s.size()+1,-1);
        
        return f(0,s,dp);
    }
//	TC(N)
	// SC(N)
};