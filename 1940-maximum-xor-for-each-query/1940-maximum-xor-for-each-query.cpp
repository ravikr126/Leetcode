class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
       int maxx= pow(2,maximumBit)-1;
       int total=nums[0];
       for(int i=1;i<nums.size();i++) total^=nums[i];
       int ans=0;
       vector<int> v;

        for(int i=0;i<nums.size();i++){
            ans= maxx^total;
            v.push_back(ans);
            total^=nums[nums.size()-1-i];
        }
        return v;
    }
};