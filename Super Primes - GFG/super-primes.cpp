// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
bool prime(int n)
{
    if(n<=1)
    return false;
    if(n==2||n==3)
    return true;
    if(n%2==0||n%3==0)
    return false;
    for(int i=5;i*i<=n;i++)
    {
        if(n%i==0||n%(i+2)==0)
        return false;
    }
    return true;
}
int superPrimes(int n)
{
  
   
   int res=0;
   int prep=3;
   for(int i=5;i<=n;i++)
   {
       if(prime(i))
       {
           if(i==prep+2)
            res++;
           prep=i;
       }
   }
   return res;
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
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends