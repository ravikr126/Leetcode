class Solution {
public:
    std::vector<int> resultsArray(std::vector<int>& nums, int k) {
        // Skip if k is 1
        if (k == 1) {
            return nums;
        }
        
        int n = nums.size();
        std::vector<int> result;
        int left = 0;
        int right = 1;
        
        while (right < n) {
            // Check if current sequence is not consecutive
            bool is_not_consecutive = nums[right] - nums[right-1] != 1;
            
            if (is_not_consecutive) {
                // Mark invalid sequences
                while (left < right && left + k - 1 < n) {
                    result.push_back(-1);
                    left++;
                }
                left = right;
            }
            // Found valid k-length sequence
            else if (right - left == k - 1) {
                result.push_back(nums[right]);
                left++;
            }
            
            right++;
        }
        
        return result;
    }
};