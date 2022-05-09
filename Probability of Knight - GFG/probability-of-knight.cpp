// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
bool inside(int x,int y,int N){
	    if(x>=0 and x<N and y>=0 and y<N) return 1;
	    return 0;
	}
	double findProb(int N,int start_x, int start_y, int steps)
	{
	    // initialize of dp
	    double dp[N][N][steps+1];
	    int dx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
        int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };
	    
	    //base case: at 0th step probability will be 1
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++) dp[i][j][0]=1;
	    }
	    
	    // now for each steps
	    for(int s=1;s<=steps;s++){
	         for(int x=0;x<N;x++){
	             for(int y=0;y<N;y++){
	                 double prob=0.0;
	                 for(int i=0;i<8;i++){
                        int nx=x+dx[i];
                        int ny=y+dy[i];
                        if(inside(nx,ny,N)) // check {nx,ny} is inside of the NxN chess board or not
                            prob+= dp[nx][ny][s-1]/8.0;
	                 }
	                 dp[x][y][s]=prob;
	             }
	         }
	    }
	    return dp[start_x][start_y][steps];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends