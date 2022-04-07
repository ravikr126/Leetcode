// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string ar[], int n)
    {
        // code here
         sort(ar,ar+n);
        string str=ar[0];
        for(int i=1;i<n;i++){
          string substr=ar[i].substr(0,str.length());
          while(str.length()>0 && substr.find(str)==string::npos){
              str.pop_back();
          }
        }
        return str.length()==0?"-1":str;
    }
};

// { Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends