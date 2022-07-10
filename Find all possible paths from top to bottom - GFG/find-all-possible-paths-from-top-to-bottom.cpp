// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> ans;

    void paths(int i, int j, int n, int m, vector<vector<int>> &v, vector<int> &cur) {

        if(i == n-1 && j == m-1) {

            cur.push_back(v[i][j]); 

            ans.push_back(cur); 

        }

      if(i!=n-1 or j!=m-1) 

        cur.push_back(v[i][j]);

        

        if(i+1 < n){

            paths(i+1,j,n,m,v,cur);

        }

        

        if(j+1 < m) {

            paths(i,j+1,n,m,v,cur);

        }

    

        cur.pop_back();

    }


 

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)

    {   

        vector<int> cur;

        paths(0,0,grid.size(), grid[0].size(),grid,cur);

        return ans;

    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends