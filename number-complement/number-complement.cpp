class Solution {
public:
    int findComplement(int num) {
       int n = num, ans = 1;
        while(n != 1){
            n >>= 1;
            ans <<= 1;
            ans |= 1;
        }
        
        ans ^= num;
        
        return ans;
    }
};