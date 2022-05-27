class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0) return 0 ;
		int bit_length = sizeof(num) * 8 - __builtin_clz(num); // 6 = 0...0110 => only [110].length = 3;
		int number_of_1s = __builtin_popcount(num); // 1s in [110] = #[1] = 2
		int operations_to_remove_0s =  bit_length -  number_of_1s; // 0s in [110] = #[0] = [110].length - #[1]
		int operations_to_remove_1s =  2 * (number_of_1s) - 1; // all 1s will take 2 operation except the last one because for last 1, 0...01 - 1 = 0 it will take only one Operation 
		return operations_to_remove_0s + operations_to_remove_1s;

    }
};