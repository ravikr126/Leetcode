// { Driver Code Starts

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int numOfPairs(int x[], int y[], int n) {
     
      int ans = 0;
        unordered_map<int,int> xFreq, yFreq;
        unordered_map<string,int> xyFreq;
    
        for(int i = 0; i < n; i++) {
            string s = to_string(x[i]) + "," + to_string(y[i]);
            ans += xFreq[x[i]] + yFreq[y[i]] - 2*xyFreq[s];
    
            xFreq[x[i]]++;
            yFreq[y[i]]++;
            xyFreq[s]++;
        }
    
       return ans;
     
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends