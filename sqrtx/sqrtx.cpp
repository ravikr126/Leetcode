class Solution {
public:
    int mySqrt(int x) {
           long int start=0;
       long int end=x;
       long int ans=0;
       while(start<=end){
           long int mid=start+(end-start)/2;
           if(mid*mid<=x)
            {  ans= mid;
              start=mid+1;
            }
            else{
                end=mid-1;
            }
             
       }
       return ans;
    }
};