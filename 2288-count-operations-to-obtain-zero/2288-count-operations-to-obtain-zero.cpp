class Solution {
public:
    int countOperations(int num1, int num2,int cnt=0) {
         return (num1==0 || num2==0)?cnt:countOperations(num2, num1%num2, cnt+num1/num2);
  
    }
};