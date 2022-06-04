// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]) {
        // code here
        vector<vector<int>> adj(N + 1);
        vector<int> deg(N + 1, 0);
        for(int i = 0; i < M; i++){
            adj[mat[i][0]].push_back(mat[i][1]);
            deg[mat[i][1]]++;
        }
        queue<int> q;
        int level = 0;
        for(int i = 1; i <= N; i++){
            if(deg[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int node = q.front();
                q.pop();
                for(int child : adj[node]){
                    deg[child]--;
                    if(deg[child] == 0){
                        q.push(child);
                    }
                }
            }
            level++;
        }
        return level;

    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends