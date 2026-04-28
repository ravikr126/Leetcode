class Solution {
public:
    int dfs(vector<vector<int>> & grid, int row, int col){
        if(row<0 || col<0 || row>= grid.size()|| col>= grid[0].size() || grid[row][col] == 0){
            return 1; // this is for water
        }
        if(grid[row][col]==-1)
            return 0;
        grid[row][col]= -1;
        return (dfs(grid, row+1,col)+dfs(grid, row-1,col)+dfs(grid, row,col-1)+dfs(grid, row,col+1) );
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int parameter=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    parameter+=dfs(grid, i, j);
                }
            }
        }
        return parameter;
    }
};