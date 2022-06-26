// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]] = 0;
        }
        int cnt = 0;
        int idx = 0;
        int ans = 0;
        int i = 0; 
        while(i < n){
            mp[arr[i]]++;
            if(mp[arr[i]] == 1){
                cnt++;
            }
            while(cnt == mp.size() && idx <= i){
                ans += n - i;
                mp[arr[idx]]--;
                if(mp[arr[idx]] == 0){
                    cnt--;
                }
                idx++;
            }
            i++;
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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends