// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int MaxGold(vector<vector<int>>&matrix){
    // Code here
     int n = matrix.size(), m = matrix[0].size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] != -1)
                dp[i][j] = matrix[i][j] + max({j > 0 ? dp[i + 1][j - 1] : 0, dp[i + 1][j + 1], dp[i + 1][j]});
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
        ans = max(ans, dp[0][i]);
    return ans;
    
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends