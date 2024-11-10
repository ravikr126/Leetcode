class Solution {
    const int mod = 1e9 + 7;
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        map<int, long long> sum, count;
        
        for(int i = 0; i < n; i++) {
            res = (res + nums[i]) % mod;
            int toFind1 = nums[i] + 1;
            int toFind2 = nums[i] - 1;
            
            long long cnt1 = count[toFind1];
            long long sum1 = sum[toFind1];
            res = (res + (cnt1 * nums[i] % mod + sum1) % mod) % mod;
            
            long long cnt2 = count[toFind2];
            long long sum2 = sum[toFind2];
            res = (res + (cnt2 * nums[i] % mod + sum2) % mod) % mod;
            
            count[nums[i]] = (count[nums[i]] + cnt1 + cnt2 + 1) % mod;
            long long curr = ((nums[i]) * (cnt1 + cnt2 + 1)) % mod;
            sum[nums[i]] = (sum[nums[i]] + sum1 + sum2 + curr) % mod;
        }
        return res;
    }
};