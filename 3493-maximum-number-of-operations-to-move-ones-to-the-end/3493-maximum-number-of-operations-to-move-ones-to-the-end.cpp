class Solution {
public:
    int maxOperations(string s) {
        int result = 0;
        int ones = 0;
        bool use = false;
        
        for (char c : s) {
            if (c == '0') {
                use = true;
            } else {
                if (use) {
                    result += ones;
                }
                ones++;
                use = false;
            }
        }
        
        if (use) {
            result += ones;
        }
        
        return result;
    }
};