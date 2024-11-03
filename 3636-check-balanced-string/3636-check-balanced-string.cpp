class Solution {
public:
    bool isBalanced(string num) {
        int evenSum = 0, oddSum = 0;
        for (int i = 0; i < num.length(); i++) {
            if (i % 2 == 0) {
                evenSum += num[i] - '0'; // Convert char to int
            } else {
                oddSum += num[i] - '0'; // Convert char to int
            }
        }
        return evenSum == oddSum;
    }
};