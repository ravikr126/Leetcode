class Solution {
public:
    int helper(vector<vector<int>>& v,vector<vector<int>> &g,int i,int j,int c){
        int n = g.size();
        int m = g[0].size();
        if(i<0 || i>=n || j<0 || j>=m || v[i][j] || (g[i][j]==-1)){
            return 0;
        }
        if(g[i][j]==2){
            if(c==1) return 1;
            return 0;
        }
        v[i][j]=1;
        int d[] = {0,1,0,-1,0};
        int ans = 0;
        for(int k=1;k<5;k++){
            int a = i+d[k];
            int b = j+d[k-1];
            ans+=helper(v,g,a,b,c-1);
        }
        v[i][j] = 0;
        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int x,y,i,j;
        vector<vector<int>> v(n,vector<int>(m,0));
        int c = n*m;
        for(int k = 0;k<n;k++){
            for(int l = 0;l<m;l++){
                if(grid[k][l]==1){
                    i = k;
                    j = l;
                }
                else if(grid[k][l]==-1){
                    c--;
                }
            }
        }

        int ans = helper(v,grid,i,j,c);
        
        return ans;
    }
};