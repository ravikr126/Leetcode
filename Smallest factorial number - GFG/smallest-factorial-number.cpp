// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
       bool check(int x, int k)
       {
           int p = 5,cnt = 0;
           while(x/p){
               cnt+=(x/p);
               p*=5;
           }
           return cnt>=k;
       }
   
       int findNum(int n)
       {
       //complete the function here
           int lo = 1, hi = INT_MAX;
           int mid,ans;
           while(lo<=hi)
           {
               mid = lo +(hi-lo)/2;
              if(check(mid,n)) {
                  ans = mid;
                  hi = mid-1;
              }
              else lo = mid+1;
           }
           return ans;
       }

      
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends