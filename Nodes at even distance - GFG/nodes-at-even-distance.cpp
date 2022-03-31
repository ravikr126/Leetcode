// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
     void dfs(vector<vector<int>> &adj, vector<bool> &visited, int &ans, int &even, int &odd, int h, int e){
        if(visited[e] == true){
            return;
        }
        visited[e] = true;
        if(h % 2){
            ans += odd;
            odd++;
        }
        else{
            ans += even;
            even++;
        }
        for(auto &i : adj[e]){
            dfs(adj, visited, ans, even, odd, h + 1, i);
        }
    }
    
    
    int countOfNodes(vector<int> graph[], int n)
    {
        vector<vector<int>> adj;
        for(int i = 0; i < n; i++){
            vector<int> row;
            adj.push_back(row);
        }
        for(int i = 1; i <= n; i++){
            for(auto &e : graph[i]){
                adj[i - 1].push_back(e - 1);
            }
        }
        int even = 0;
        int odd = 0;
        int ans = 0;
        vector<bool> visited (n , false);
        dfs(adj, visited, ans, even , odd, 0, 0);
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
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends