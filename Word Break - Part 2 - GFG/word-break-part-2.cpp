// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
  vector<string>ans;
void solve(int n, vector<string> &dict, string s, int i, string a, string b)
{
   if (i == s.size())
   {
       if (a == s)
       {
           ans.push_back(b);
       }
       return;
   }

   string c = b;
  
   for (int j = 0; j < n; j++)
   {
       string k = dict[j];
       if (k[0] == s[i])
       {

           if (i == 0)
           {
               // b+="(";
           }
           b.append(k);

           if (i + k.size() >= s.size())
           {
               // b.append(")");
           }
           else
           {
               b.append(" ");
           }
           solve(n, dict, s, i + k.size(), a + k, b);
       }
       b = c;
   }    
}
   vector<string> wordBreak(int n, vector<string>& dict, string s)
   {
       // code here
   string a = "", b = "";
   solve(n,dict,s,0,a,b);
   return ans;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends