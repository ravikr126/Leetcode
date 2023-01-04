//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
   int memo[50001] = {};

    int dfs(vector<vector<int>>& comb, int pos, int last){

        if(pos >= comb.size()) return 0; 

        if(comb[pos][0] < last) return dfs(comb, pos+1, last); 

        if(memo[pos] != -1) return memo[pos]; 

        int ans = 0;

        ans = max(dfs(comb, pos+1, comb[pos][1])+comb[pos][2], dfs(comb, pos+1, 0));

        return memo[pos] = ans;

    }

  public:

      int maximum_profit(int n, vector<vector<int>> &in) {

          

        sort(in.begin(),in.end());

        

         memset(memo, -1, sizeof memo);



      

        return dfs(in, 0, 0);

        

      }

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends