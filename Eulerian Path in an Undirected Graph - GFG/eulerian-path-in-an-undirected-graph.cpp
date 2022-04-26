// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int eulerPath(int N, vector<vector<int>> graph){
        // code here
           int even=0,odd=0;
       
       for(int i=0;i<N;i++)
       {
           int t=0;
           
           for(int j=0;j<N;j++)
           {
               if(graph[i][j]==1)
               t++;
           }
           t%2==0? even++:odd++;
       }
       
       return (odd>2 or odd<2)==0?1:0;
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j = 0;j < N;j++)
                cin>>graph[i][j];
        
        Solution ob;
        cout<<ob.eulerPath(N, graph)<<"\n";
    }
    return 0;
}  // } Driver Code Ends