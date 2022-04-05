// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int countSquare(int b)
    {
	    // code here
	    if(b&1)
	        b-=1;
	   // now the answer would be really easy, 
	   // x=max no of squares of size 2*2 units that can fit in the right-angled isosceles triangle with base b        
       // x=((max no of squares of size 2*2 units that can fit in the square of b*b)-(squares of 2*2 presented on the diagonal))/2
       // x=(b*b/2*2)-(squares on the diagonal)/2
       // x=((b*b)/(2*2)-(b/2))/2
       // x=b*(b-2)/8;
       return b*(b-2)/8; 
    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int B,count;
    	cin>>B;
    	Solution ob;
    	count = ob.countSquare(B);
    	cout<<count<<endl;
    }
}  // } Driver Code Ends