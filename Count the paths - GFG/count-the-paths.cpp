// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int dfs(int s, int d, vector <int> adj[]){
        if(s == d)
            return 1;
        int c = 0;
        for(auto &i:adj[s])
            c += dfs(i, d, adj);
        return c;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector <int> adj[n+1];
	    for(auto &i:edges)
	        adj[i[0]].push_back(i[1]);
	    return dfs(s, d, adj);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends