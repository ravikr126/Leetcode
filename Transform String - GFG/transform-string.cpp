// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
          string a=A,b=B;
       sort(a.begin(),a.end());
       sort(b.begin(),b.end());
       if(a.length()!=B.length()) return -1;
      for(int i=0;i<a.length();i++) if(a[i]!=b[i]) return -1;
       int i=A.length()-1,j=0,k=B.length()-1;
        while(i>=0&&k>=0){
           
            if(A[i]!=B[k]){
                i--; j++;
            }
            else {
                i--;k--;
            }
            
        }
        
        return j;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends