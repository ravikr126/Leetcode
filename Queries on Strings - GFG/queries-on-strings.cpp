// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    // Code here
	      int n = str.length();
	    vector<vector<int>>dp(n , vector<int>(26 , 0));
	    for(int i = 0 ; i < n ; i++){
	        dp[i][str[i] - 'a']++;
	    }
	    for(int i = 1 ; i < n ; i++){
	        for(int j = 0 ; j < 26 ; j++){
	            dp[i][j] += dp[i - 1][j];
	        }
	    }
	    vector<int>ans;
	    for(auto it : Query){
	        int distinct = 0;
	        int l = it[0] , r = it[1];
	        l-- , r--;
	        for(int j = 0 ; j < 26 ; j++){
	            int cnt = dp[r][j];
	            if(l)
	            cnt -= dp[l - 1][j];
	            if(cnt)
	            distinct++;
	        }
	        ans.push_back(distinct);
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends