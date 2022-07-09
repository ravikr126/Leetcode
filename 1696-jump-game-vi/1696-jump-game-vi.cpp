class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
      vector<int> dp(nums.size());
        int n = nums.size();
        priority_queue<int> pq;
        dp[n-1]=nums[n-1];
        deque<int> dq;
        dq.push_back(n-1);
      
        for(int i=n-2;i>=0;i--){
          
            int a = nums[i];
            while(dq.size() && dq.front()>i+k){
                dq.pop_front();
            }
            int next  = dp[dq.front()];
            
          dp[i] = a+next;
           
          while(dq.size() && dp[dq.back()]< dp[i]){
              dq.pop_back();
          }  
           
            dq.push_back(i); 
        }
        
        return dp[0];
    }
};