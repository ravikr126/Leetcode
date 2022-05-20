// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string s1, string s2) {
        // code here
         unordered_map<char, int>mp;
        
        for(int i=0;i<s1.length();i++)
        {
            mp[s1[i]] = i;
        }
        
        int ans=0;
        int iniptr = mp[s1[0]];
        for(int i=0;i<s2.length();i++)
        {
            int ptr = 0;
            ptr =  mp[s2[i]];
            ans += abs(mp[s2[i]] - iniptr);
            iniptr = ptr;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends