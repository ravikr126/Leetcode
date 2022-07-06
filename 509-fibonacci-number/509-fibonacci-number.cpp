class Solution {
public:
    int fib(int n) {
         double ratio = (sqrt(5) + 1) / 2;
        
       double uptopowers = 1;
       while (n > 0) 
       {
           if(n & 1) // n is odd
           {
               uptopowers *= ratio;
           }
           
           ratio = ratio * ratio;
           n = n >> 1; // n = n / 2;
       }
        
        return round(uptopowers / sqrt(5));
    }
};