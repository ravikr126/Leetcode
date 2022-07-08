// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution{
public:
    pair<int, string> solve(int p[], int n, int low, int high, pair<int, string> dp[27][27])
    {
        if(low == high)
        {
            char ch = 'A' + low;
            string s = "" ; 
            s += ch;
            pair<int, string> pr = {0, s};
            return pr;
        }
        
        if(dp[low][high].first != -1)
            return dp[low][high];

        pair<int, string> ans;
        ans.first = INT_MAX;
        for(int i=low; i<high; i++)
        {
            pair<int, string> p1 = solve(p, n, low, i, dp);
            pair<int, string> p2 = solve(p, n, i+1, high, dp);
            
            int temp = p1.first + p2.first + (p[low] * p[i+1] * p[high+1]);
            if(ans.first > temp)
            {
                ans.first = temp;
                ans.second = "(" + p1.second + p2.second + ")";
            }
        }
        return dp[low][high] = ans;
    }
    string matrixChainOrder(int p[], int n){
        pair<int, string> dp[27][27];
        pair<int, string> empty; empty.first = -1;
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                dp[i][j] = empty;
        return solve(p, n, 0, n-2, dp).second;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends