class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       return accumulate(nums.begin(), nums.end(), 0, [&](int sum, int x){
            return sum+(x%3!=0);
        });   
    }
};