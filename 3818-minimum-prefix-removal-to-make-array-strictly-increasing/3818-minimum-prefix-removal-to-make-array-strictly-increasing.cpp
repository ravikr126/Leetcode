class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
            int i = nums.size() - 1;
        while (i > 0 && nums[i - 1] < nums[i]) 
            --i;
        return i;
    }
};