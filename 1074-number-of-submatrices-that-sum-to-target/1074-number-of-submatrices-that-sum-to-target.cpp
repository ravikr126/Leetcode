class Solution {
public:
   // this part you have already solve on leetcode here we are just solving famous leetcode problem number of subarrays with sum k
// we are just converting this bigger problem into one of the most renowed problem
	
	int solve(vector<int>&nums,int k)
{unordered_map<int,int>mp;
 int cs=0;
 int ans=0;
 for(int i=0;i<nums.size();++i)
 {
     cs+=nums[i];
     if(cs==k)
     {
        ans++; 
     }
     if(mp.find(cs-k)!=mp.end())
     {
         ans+=mp[cs-k];
      
     }
     mp[cs]++;
 }
 return ans;
    
}
int numSubmatrixSumTarget(vector<vector<int>>& a, int t) {
     int ans=0;
    //we will actually work row wise because we already know  the problem to find number of subarray in a row with a given sum
    for(int srow=0;srow<a.size();++srow)
    {vector<int>v(a[0].size(),0);
        for(int crow =srow;crow<a.size();++crow)//crow-->currrow
        {
            // now storing sum in  a particular array
            for(int j=0;j<a[0].size();++j)
            {
                v[j]+=a[crow][j];
            }
            ans+=solve(v,t);
        }
    }
    
    return ans;
}

};