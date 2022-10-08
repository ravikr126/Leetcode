class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
        int n=nums.size();
        int ansSum=0;
        int diff=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int start=i+1,end=n-1;
            int first=nums[i];
            while(start<end)
            {
                if(first+nums[start]+nums[end] == target)
                    return first+nums[start]+nums[end];
                else if(abs(first+nums[start]+nums[end]-target)<diff)
                {
                    diff=abs(first+nums[start]+nums[end]-target);
                    ansSum=first+nums[start]+nums[end];
                }

                if(first+nums[start]+nums[end] > target)
                    end--;
                else if(first+nums[start]+nums[end] < target)
                    start++;
            }
        }   

        return ansSum;
    }
};