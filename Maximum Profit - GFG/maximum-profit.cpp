// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int a[]) {
        // code here
           int dp[k+1][n];
       memset(dp,0,sizeof(dp));
       for(int i=1;i<=k;i++)
       {
           int mx=INT_MIN;
           for(int j=1;j<n;j++)
           {
               mx=max(mx,dp[i-1][j-1]-a[j-1]);
               dp[i][j]=max(dp[i][j-1],mx+a[j]);
           }
       }
       return dp[k][n-1];
   }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends