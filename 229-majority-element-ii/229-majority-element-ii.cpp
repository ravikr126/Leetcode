class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int cnt=nums.size()/3;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(auto it:mp){
            if(it.second>cnt){
                res.push_back(it.first);
            }
        }
        return res;
    }
};