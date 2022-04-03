class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
          int l = 0;
        int r = nums.size() - 1;
        int mid ;
        while (l <= r)
        {
            mid= l + (r-l)/2;
            
            
            if (nums[mid] >nums[mid-1] && nums[mid] >nums[mid+1])
                return mid;
            
            if (nums[mid] >nums[mid-1] && nums[mid] <nums[mid+1])
                l = mid ;
            if (nums[mid] <nums[mid-1] && nums[mid] >nums[mid+1])
                r = mid;
        }
        
        return mid;
    }
};