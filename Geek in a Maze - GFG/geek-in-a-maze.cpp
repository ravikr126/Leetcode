// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
 
	public:
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
	{
		// Your code goes here
		queue<vector<int>> q;
		q.push({r,c,0,0});
		if(mat[r][c]=='#') return 0;
		mat[r][c] = 1;
		int count=1;
		while(!q.empty()){
		    int x = q.front()[0];
		    int y = q.front()[1];
		    int up = q.front()[2];
		    int down = q.front()[3];
		    
		    // right
		    if(y+1<m && mat[x][y+1]=='.'){
		        q.push({x,y+1,up,down});
		        mat[x][y+1]='1';
		        count++;
		    }
		    //left
		     if(y-1>=0 && mat[x][y-1]=='.'){
		        q.push({x,y-1,up,down});
		        mat[x][y-1]='1';
		        count++;
		    }
		    // up
		     if(x-1>=0 && mat[x-1][y]=='.' &&up!=u){
		        q.push({x-1,y,up+1,down});
		        mat[x-1][y]='1';
		        count++;
		    }
		    //down..
		    if(x+1<n && mat[x+1][y]=='.' && down!=d){
		        q.push({x+1,y,up,down+1});
		        mat[x+1][y]='1';
		        count++;
		    }
		    q.pop();
		}
		return count;
		
	}

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;

    while (t--)
    {
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    }

    return 0;
}


  // } Driver Code Ends