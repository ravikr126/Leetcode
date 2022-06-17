// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool bfs(vector<int> adj[], int V, int src, vector<int> &vis){
       queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(q.size()){
        int v = q.front();
        q.pop();
        int color = vis[v];
        for(auto nbr: adj[v]){
            if(vis[nbr] == color) return false;
            if(vis[nbr]) continue;
            vis[nbr] = 3 - color;
            q.push(nbr);
        }
    }
    return true;
   }
   
bool isBipartite(int V, vector<int>adj[]){
    // Code here
    vector<int> vis(V, 0);
    bool res = true;
    for(int i=0; i < V and res; ++i){
        if(vis[i]) continue;
        res = bfs(adj, V, i, vis); 
    }
    return res;
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends