class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxi=0;
        sort(nums.begin(),nums.end());
        int siz= nums.size();
        int i=0;
        while(i<siz/2){
            int sum= nums[i]+nums[siz-i-1];
            maxi=max(maxi,sum);
            i++;
        }
        return maxi;
    }
};