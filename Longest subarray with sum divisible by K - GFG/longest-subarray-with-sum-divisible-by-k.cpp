// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	     unordered_map<int,int>mp;
    long long sum=0;
    int ans=0;
    mp[0]=-1;
    for(int i=0;i<n;i++)
    {
        sum=(sum%k + arr[i]%k+k)%k;
        if(mp.find(sum)!=mp.end())
        {
            ans = max(ans,i-mp[sum]);
        }
        else
            mp[sum]=i;
    }
    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends