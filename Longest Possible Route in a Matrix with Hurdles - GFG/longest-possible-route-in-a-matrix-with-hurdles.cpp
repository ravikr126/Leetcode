// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
   {
       int c=0;
       vector<vector<int>> v(matrix.size(),vector<int>(matrix[0].size(),0));
       int x=f(matrix,xs,ys,xd,yd,c,v);
       return(x);
       
       
   }
 
   int f(vector<vector<int>> matrix, int xs, int ys, int xd, int yd,int c,vector<vector<int>> v)
   {
       int a1=-1,a2=-1,a3=-1,a4=-1;
       if(matrix[xs][ys]==0)
       return(-1);
       if(xs==xd && ys==yd)
       return(c);
       
       
       
       if(matrix.size()>xs+1 && v[xs+1][ys]==0)
       {
           
           v[xs][ys]=1;
           a1=f(matrix,xs+1,ys,xd,yd,c+1,v);
       }
       
       if(xs-1>=0 && v[xs-1][ys]==0)
       {
           
           v[xs][ys]=1; 
           a2=f(matrix,xs-1,ys,xd,yd,c+1,v);
       }
       if(ys+1<v[0].size()&&v[xs][ys+1]==0)
       {
           
           v[xs][ys]=1;
           a3=f(matrix,xs,ys+1,xd,yd,c+1,v);
       }
       if(ys-1>=0 && v[xs][ys-1]==0)
       {
           
           v[xs][ys]=1;
           a4=f(matrix,xs,ys-1,xd,yd,c+1,v);
       }
       if(a1==-1 && a2==-1 && a3==-1 && a4==-1 )
       return(-1);
       
       return(max(a1,max(a2,max(a3,a4))));
       
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
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends