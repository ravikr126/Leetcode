class Solution {
public:
    int arrangeCoins(int n) {
        if(n==1) return 1;
        int i=0;
        for(i=0;i<31;i++){
            if(pow(2,i)==n) return i;
            if(pow(2,i)>n) return i-1;
        }
        return -1;
    }
};