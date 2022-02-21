class Solution {
public:
    int majorityElement(vector<int>& nums) {
       sort(nums.begin(),nums.end()); // sort the vector
        return nums[nums.size()/2];     // middle element will be the most frequent Element
  
    }
};