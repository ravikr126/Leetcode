class Solution {
public:
    int pivotIndex(vector<int>& nums) {
         int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int ls=0;
        int rs = sum;
        for(int i=0;i<nums.size();i++)
        {
            rs -=nums[i];
            if(ls==rs)
            {
                return i;
            }
             ls += nums[i];
            
        }
        return -1;
    }
};