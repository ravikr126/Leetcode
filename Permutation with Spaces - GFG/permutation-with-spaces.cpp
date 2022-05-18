// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:

   void rec(int i, string s, string curr, vector<string> &ans) {
       
       
       if(i == s.length()) {
           ans.push_back(curr);
           return;
       }
       
       if(i != 0)
           rec(i + 1, s, curr + " " + s[i], ans);
       rec(i + 1, s, curr + s[i], ans);
   }

   vector<string> permutation(string s){
       vector<string> ans;
       
       string curr = "";
       
       rec(0, s, curr, ans);
       
       return ans;
   }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends