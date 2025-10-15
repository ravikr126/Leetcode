class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes = 0;
        int i = 0, j = 0;
        int n = nums.size();
        int ans = 0;
        while(j < n){
            if(nums[j] == 1) j++;
            else if (nums[j] == 0){
                if(zeroes < k) {zeroes++; j++;}
                else{
                    if(nums[i] == 0) zeroes--;
                    i++;
                }
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};