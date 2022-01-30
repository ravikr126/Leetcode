class Solution {
public:
   void reverse(int se,int end,vector<int>& nums){
while(se<=end){
swap(nums[se],nums[end]);
se++;
end--;
}
   }
    void rotate(vector<int>& nums, int k) {
       
         int n=nums.size()-1;
    if(n==0){
        return;
    }
    k=k%(n+1);
    
       
    reverse(n-k+1,n,nums);
    reverse(0,n-k,nums);
    reverse(0,n,nums);

    }
};