// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int sum(int a , int b)
    {
        //code here
        //1st option
        //  if(a == b) return 2 * a;
        // else return (a * 1LL * a - b * 1LL* b) / (a - b);
        
        //2nd
        int x = a ^ b;
        int carry = a & b;
        while(carry!=0){
            a = x;
            b = (carry<<1);
            x = a ^ b;
            carry = a & b;
        }
        return x;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends