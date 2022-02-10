class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
    
    mp[0]++;
    
    int n=nums.size();
    int sum=0,count=0;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        
        if(mp.find(sum-k) !=mp.end())
        {
            auto it=mp.find(sum-k);
            count+=(it->second);
        }
        mp[sum]++;
    }
    
    return count;
    }
};