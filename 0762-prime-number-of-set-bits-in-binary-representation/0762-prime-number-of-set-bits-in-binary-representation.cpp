// new variant
class Solution {
public:
    static int countPrimeSetBits(int left, int right) {
        int prime[]={2, 3, 5, 7, 11, 13, 17, 19};
        bitset<21> isPrime=0;
        for(int p: prime) isPrime[p]=1;
        int sum=0;
        for(unsigned i=left; i<=right; i++){
            int b=popcount(i);
            if (isPrime[b]) sum++;
        }
        return sum;
    }
};