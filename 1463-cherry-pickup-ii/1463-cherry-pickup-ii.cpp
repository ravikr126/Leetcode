class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<int> dir={-1,0,1};
        // let's define array size
        int row = grid.size();
        int col = grid[0].size();
        int dp[row][col][col]; // we need to have a 3D array
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                for(int k = 0; k < col; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        int col1 = 0; // first robot position
        int col2 = col - 1; // second robot position
        
        dp[0][col1][col2] = grid[0][col1] + grid[0][col2]; // we have the value of 0th row from where we will be starting;
        
        int ans = dp[0][col1][col2]; // intially we have the max value of the column that we will be started with;
        
        // now comes a part where we need to iterate over each row;
        for(int i = 1; i < row; i++){
            for(int c1 = 0; c1 < col; c1++){ // need to loop on each column precise in the row
                for(int c2 = 0; c2 < col; c2++){
                    // now from every column we need to fill the cube; for all the combinations or all the cell we can reach; with respective robot1 & robot2
                    int prev = dp[i - 1][c1][c2];
                    if(prev >= 0){
                        for(int d1: dir){
                            col1 = d1 + c1;
                            for(int d2: dir){
                                col2 = d2 + c2;
                            
                                if(inRange(col1, col) && inRange(col2, col)){
                                    dp[i][col1][col2] = max(dp[i][col1][col2], prev+(col1 == col2 ? grid[i][col1] : (grid[i][col1] + grid[i][col2])));
                                    ans = max(ans, dp[i][col1][col2]);
                                }
                            }
                        }
                    }
                    
                }
            }
        }
        return ans;
    }
    bool inRange(int val, int limit){
        return 0 <= val && val < limit;
    }
};