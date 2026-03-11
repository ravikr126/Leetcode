class Solution {
public:
    int bitwiseComplement(unsigned n) {
          if (n == 0) return 1;
             return ~n & (1 << bit_width(n)) - 1;
    }
};