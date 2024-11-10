class Solution {
public:
    bool f(int mid,vector<int>& suff,vector<int>& nums){
        int i=0;
        while(i<=(nums.size() - (2*mid))){
            if(suff[i]>=mid && suff[i+mid]>=mid){
                return true;
            }
            i++;
        }
        return false;
    }
    int binarySearch(vector<int>& nums,vector<int>& suff){
        int left=1,right=nums.size()/2;
        int result=0;
        while(left<=right){
            int mid = (left) + (right-left)/2;
            if(f(mid,suff,nums)){
                result = mid;
                left=mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return result;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int size=nums.size();
        vector<int> suff(size,1);
        for(int i=size-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                suff[i]=suff[i+1]+1;
            }
        }
        int result = binarySearch(nums,suff);
        return result;
    }
};