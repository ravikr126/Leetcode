class Solution {
public:
    int divide(int x, int y) {
        int sign = ((x<0)^(y<0))?-1:+1;
        long long dividend = x, divisor=y,q=0;
        dividend=abs(dividend), divisor = abs(divisor);
        for(int i=31;i>=0;i--){
            if((divisor<<i) > dividend) continue;  
            q |= (1LL<<i);
            dividend -=  (divisor<<i);
        }
        q*=sign;
        if(q<0 and q<INT_MIN) q=INT_MIN;
        if(q>0 and q>INT_MAX) q=INT_MAX;
        return q;
    }
};