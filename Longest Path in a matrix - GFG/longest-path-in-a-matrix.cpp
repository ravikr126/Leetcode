// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isvalid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
int help(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (!isvalid(i, j, n, m))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int l = 0, r = 0, u = 0, d = 0;

    if (isvalid(i, j - 1, n, m) && matrix[i][j] > matrix[i][j - 1])
        l = help(i, j - 1, n, m, matrix, dp);

    if (isvalid(i, j + 1, n, m) && matrix[i][j] > matrix[i][j + 1])
        r = help(i, j + 1, n, m, matrix, dp);

    if (isvalid(i - 1, j, n, m) && matrix[i][j] > matrix[i - 1][j])
        u = help(i - 1, j, n, m, matrix, dp);

    if (isvalid(i + 1, j, n, m) && matrix[i][j] > matrix[i + 1][j])
        d = help(i + 1, j, n, m, matrix, dp);

    return dp[i][j] = 1 + max(max(max(l, r), u), d);
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    // Code here
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dp[i][j] == -1)
                ans = max(ans, help(i, j, n, m, matrix, dp));

    return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends