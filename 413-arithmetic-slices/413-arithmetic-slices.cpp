class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
       if(nums.size() < 3)
            return 0;
        
        int cnt = 0, diff = 0 , ind = 0;
        int prev_diff = nums[1] - nums[0];
        
        for(int i = 1; i<nums.size()-1 ; ++i)
        {
            // curr difference
            int diff = nums[i+1] - nums[i];
            
            // if we find same diff of consecutive elements
            // increase count
            if(diff ==  prev_diff)
                ++ind;
            
            else
            {
                // update prev diff with curr diff
                // as we don't find consecutive elements with same diff
                prev_diff = diff;
                ind = 0;  // make ind to 0
            }
            
            // add cosecutive arithmetic sequence cnt
                cnt += ind;
        }
        
       
        return cnt;
    }
};