// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
   int fun(string &s) {
       long long a = 0, ab = 0, abc = 0, mod = 1e9 + 7;
       for(auto c: s){
           switch(c){
               case 'a':
               a = (2 * a + 1)%mod;
               break;
               
               case 'b':
               ab = (2 * ab % mod + a)%mod;
               break;
               
               case 'c':
               abc = (2 * abc % mod + ab)%mod;
           }
       }
       return abc;
   }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends