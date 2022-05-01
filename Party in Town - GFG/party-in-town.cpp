// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   

int BFS(vector<vector<int>> &adj,int i,vector<int> vis)
{
queue<int> q;
q.push(i);
int cnt=0;
vis[i]=1;
while(!q.empty())
{
int n=q.size();
while(n--)
{
int temp=q.front();
q.pop();
vis[temp]=1;
for(auto m:adj[temp])
{
if(vis[m]==0)
{
q.push(m);
}
}
}
cnt++;
}
return cnt-1;
}

int partyHouse(int N, vector<vector<int>> &adj){
// code here
int ans=INT_MAX;

for(int i=1;i<=N;i++)
{
vector<int> vis(N+1,0);
int x=BFS(adj,i,vis);
ans=min(ans,x);
}
return ans;
}
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends