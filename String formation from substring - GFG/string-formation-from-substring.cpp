// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    // Your code goes here
	      int n=s.length(),j=0,k;
	    string str="";
	    
	    while(j<(n/2)){
	        if(!(n%(j+1))){
	            k=n/(j+1);
	            str="";
	            while(k!=0){
	                str+=s.substr(0,j+1);
	                k--;
	            }
	            if(str==s) return 1;
	        }
	        j++;
	    }
	    return 0;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends