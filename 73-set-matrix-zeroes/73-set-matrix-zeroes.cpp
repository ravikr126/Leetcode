class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int n = size(nums);
          int m = size(nums[0]);
          int frow = 0; int fcol = 0; 
          if(nums[0][0] == 0){
              frow++; fcol++;
          }
          for(int i=0;i<n;i++) {
              if(nums[i][0] == 0) fcol++;
          }
          for(int j=0;j<m;j++) {
              if(nums[0][j] == 0){
                  frow++;
              }
          }
          for(int i=1;i<n;i++){
              for(int j=1;j<m;j++){
                 if(nums[i][j] == 0){
                        nums[0][j] = 0;
                        nums[i][0] = 0;
                  }
              }
          }
        
         for(int j=1;j<m;j++){
             if(nums[0][j] == 0 or nums[0][j] == 0){
                 for(int i=0;i<n;i++){
                     nums[i][j] = 0;
                 }
             }
         }
        
         for(int i=0;i<n;i++){
             if(nums[i][0] == 0 or nums[i][0] == 0){
                 for(int j=0;j<m;j++){
                     nums[i][j] = 0;
                 }
             }
         }
        
        if(frow){
            for(int j=0;j<m;j++) nums[0][j] = 0;
        }

        // cout <<"\n";
        if(fcol){
            for(int i=0;i<n;i++) nums[i][0] = 0;
        }
    
    }
};