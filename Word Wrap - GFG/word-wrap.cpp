// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
   int kk,n,m;
   int square(int n){return n*n;}
   unordered_map<int, unordered_map<int,int>>mp;
   int rec(vector<vector<int>>&vec,int i,int j)
   {
       if(j>=m)return 0;
       if(i>=n)return 99999;
       if(mp[i][j]!=0)return mp[i][j];
       if(vec[i][j]<=kk)
       {
           mp[i][j]=min(square(kk-vec[i][j])+rec(vec,j+1,j+1),rec(vec,i,j+1));
       }
       else
       {
           mp[i][j]=square(kk-vec[i][j-1])+rec(vec,j,j+1);
       }
       return mp[i][j];
   }
   int solveWordWrap(vector<int>nums, int k) 
   { 
       kk=k;m=nums.size();n=m;
       vector<vector<int>>vec(m);
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<=i;j++)
           {
               vec[i].push_back(nums[j]);
           }
           for(int j=i+1;j<m;j++)
           {
               vec[i].push_back(nums[j]+vec[i][j-1]+1);
           }
       }
       return rec(vec,0,0);
   } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends