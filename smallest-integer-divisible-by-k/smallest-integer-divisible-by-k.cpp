class Solution {
public:
    int smallestRepunitDivByK(int k) {
      // 1st method
        
        // if (k % 2 == 0 || k % 5 == 0) return -1;  // this trick may save a little time
        int hit[100000] = {0}, n = 0, ans = 0;
        while (true) { // at most k times, because 0 <= remainder < k
            ++ ans;
            n = (n * 10 + 1) % k; // we only focus on whether to divide, so we only need to keep the remainder.
            if (n == 0) return ans; // can be divisible
            if (hit[n]) return -1; // the remainder of the division repeats, so it starts to loop that means it cannot be divisible.
            hit[n] = 1;
        }
        
        
        
        //2nd method
        
         int remainder = 0;
        if(k%2==0 || k%5==0){
            return -1;
        }
        for (int length_N = 1; length_N <= k; length_N++) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) {
                return length_N;
            }
        }
        return -1;
        
//         Runtime: 3 ms, faster than 58.82% of C++ online submissions for Smallest Integer Divisible by K.
//         Memory Usage: 5.9 MB, less than 83.19% of C++ online submissions for Smallest Integer Divisible by K.
        
        
        
    }
    
};
