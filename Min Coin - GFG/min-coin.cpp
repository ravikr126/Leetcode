// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	      int n=nums.size();
    vector<int> prev(amount+1),curr(amount+1);
    
    for(int Amount=0;Amount<=amount;Amount++)
    {
        if(Amount%nums[0]==0) prev[Amount]=Amount/nums[0];
        else if(Amount==0) prev[Amount]=0;
        else prev[Amount]=1e4;
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int Amount=0;Amount<=amount;Amount++)
        {
              int NotPick=0+prev[Amount];
                 int Pick=1e4;
                 if(nums[ind]<=Amount)
                 {
                     Pick=1+curr[Amount-nums[ind]];
                 }
                  curr[Amount]=min(NotPick,Pick);
        }
        prev=curr;
    }
    int val=prev[amount];
    if(val==1e4) return -1;
    return val;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends