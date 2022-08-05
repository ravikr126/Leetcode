class Solution {  
    int dfs(vector<int>& nums, int k, vector<int>& cacheMoney) {
        if(k == 0) 
            return 1;   
        
        if(cacheMoney[k] != -1) 
            return cacheMoney[k];
        
        int howManyWays = 0;
        for(int x : nums) {
            if(k >= x) {
                howManyWays += dfs(nums, k-x, cacheMoney);
            }
        }    
        return cacheMoney[k] = howManyWays; 
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cacheMoney(target+1, -1);      
        return dfs(nums, target, cacheMoney);
    }
};