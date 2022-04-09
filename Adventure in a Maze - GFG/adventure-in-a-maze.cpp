// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
vector<int> FindWays(vector<vector<int>>&matrix){
    // Code here
      int n=matrix.size();
   int m=matrix[0].size();
   int mod=1e9 + 7;
   vector<vector<long long>>dp(n,vector<long long>(m,0));
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(i==0 && j==0){
               dp[i][j]=1;
           }
           else if(i==0){
               if(matrix[i][j-1]!=2)dp[i][j]=dp[i][j-1];
               else dp[i][j]=0;
               
           }
           else if(j==0){
               if(matrix[i-1][j]!=1)dp[i][j]=dp[i-1][j];
               else dp[i][j]=0;
           }
           else {
               if(matrix[i-1][j]!=1)dp[i][j]+=dp[i-1][j];
               if(matrix[i][j-1]!=2)dp[i][j]+=dp[i][j-1];
           }
           dp[i][j]%=mod;
       }
   }
   int path=dp[n-1][m-1]%mod;
 for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           dp[i][j]=0;
       }
}
  for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(i==0 && j==0){
               dp[i][j]=matrix[i][j];
           }
           else if(i==0){
               if(matrix[i][j-1]!=2 && dp[i][j-1]!=0)dp[i][j]=dp[i][j-1]+matrix[i][j];
               else dp[i][j]=0;
               
           }
           else if(j==0){
               if(matrix[i-1][j]!=1 && dp[i-1][j]!=0)dp[i][j]=dp[i-1][j]+matrix[i][j];
               else dp[i][j]=0;
           }
           else {
               if(matrix[i-1][j]!=1 && dp[i-1][j]!=0)dp[i][j]+=dp[i-1][j]+matrix[i][j];
               if(matrix[i][j-1]!=2 && dp[i][j-1]!=0)dp[i][j]=max(dp[i][j],dp[i][j-1]+matrix[i][j]);
           }
       }
   }
   return {path,dp[n-1][m-1]};

}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends