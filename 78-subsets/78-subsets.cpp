class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
                vector<vector<int> > ans;
        ans.push_back(vector<int>());
        for(int i = 0; i < nums.size(); i++) {
            int curSize = ans.size();
            for(int j = 0; j < curSize; j++) {
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            }
        }
        return ans;
        
    }
};