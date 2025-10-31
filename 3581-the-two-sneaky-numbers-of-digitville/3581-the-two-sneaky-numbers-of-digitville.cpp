class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        int xorSum = 0;
        int totalSize = nums.size();
        int actualSize = nums.size() - 2;

        // XOR all elements of the array
        for(int i = 0; i < totalSize; i++) {
            xorSum ^= nums[i];
        }

        // XOR all numbers from 0 to n-1 (excluding the two sneaky numbers)
        for(int i = 0; i < actualSize; i++) {
            xorSum ^= i;
        }

        // Find the rightmost set bit in xorSum
        int rightmostSetBit = xorSum & ~(xorSum - 1);

        int firstSneakyNumber = 0;
        int secondSneakyNumber = 0;

        // Separate the numbers into two groups based on the rightmost set bit
        for(int i = 0; i < totalSize; i++) {
            if(nums[i] & rightmostSetBit) {
                firstSneakyNumber ^= nums[i];
            } else {
                secondSneakyNumber ^= nums[i];
            }
        }
        
        // XOR the range of numbers from 0 to n-1
        for(int i = 0; i < actualSize; i++) {
            if(i & rightmostSetBit) {
                firstSneakyNumber ^= i;
            } else {
                secondSneakyNumber ^= i;
            }
        }

        return {firstSneakyNumber, secondSneakyNumber};
    }
};