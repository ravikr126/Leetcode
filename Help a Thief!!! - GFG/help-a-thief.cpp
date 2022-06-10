// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        if(T==0 || N==0) return 0;
        priority_queue<pair<int,int>> q;
        for(int i=0;i<N;i++)
        q.push({B[i],A[i]});
        int ans=0;
        while(T>0 && !q.empty())
        {
            pair<int,int> t=q.top();
            q.pop();
            if(t.second <=T) 
            {
                ans+= (t.first*t.second);
                T-=t.second;
            }
            else
            {
                 ans+= (t.first*T);
                T=0;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends