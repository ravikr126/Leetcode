// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
        // code here
          vector<int>v(2);
       double var=0;
       for(int i=1;i<=10000;i++){
           double x=double(i*n)/double(d);
           if(x==int(x))
           {
              x=int(x)-1;
           }
           else
           {
              x=int(x);
           }
           if(double(x)/double(i)<double(n)/double(d))
           {
              if(var<double(x)/double(i))
              {
                 v={x,i};
                 var=double(x)/double(i);  
              }
           }
       }
       return v;  
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends