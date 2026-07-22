class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start=0;
        int end=start+1;
        vector<int> v;
        while(start<nums.size()){
            if(nums[start]+nums[end]==target){
                // cout<<"hi"<<nums[start]<<" "<<nums[end]<<endl;
                v.push_back(start);
                v.push_back(end);
                break;
            }
            if(end+1 < nums.size()){
                end++;
            }else{
                start++;
                end=start+1;
            }
        }
        return v;
    }
};