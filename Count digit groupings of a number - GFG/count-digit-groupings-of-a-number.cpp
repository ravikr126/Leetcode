// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
vector<vector<int>> dp;
    int helper(string str, int i, int prev) {
        if(i == str.size()) 
            return 1;
        
        if(dp[i][prev] != -1) 
            return dp[i][prev];
        
        int ans = 0, curr = 0;
        for(int j = i; j < str.size(); j++) {
            curr += str[j] - '0';
            if(curr >= prev) {
                ans += helper(str, j+1, curr);
            }
        }
        
        return dp[i][prev] = ans;
    }
    
	public:
	int TotalCount(string str){
	    // Code here
	    int num = 0;
	    for(int i = 0; i < str.size(); i++) {
	        num += str[i] - '0';
	    }
	    
	    dp.resize(str.size() + 1, vector<int>(num + 1, -1));
	    
	    return helper(str, 0, 0);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends