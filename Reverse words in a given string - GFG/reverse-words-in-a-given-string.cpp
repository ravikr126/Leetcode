// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stack<string> st;
        string s = "";
        
        for(int i=0; i<S.length(); i++){
            
            if(S[i]!='.'){
                s += S[i]; 
            }
            if(S[i]=='.'){
                st.push(s);
                s = "";
            }
        }
        
        st.push(s);
        
        string res = "";
        while(!st.empty()){
            string temp = st.top();
            st.pop();
            
            res += temp + ".";
        }
        res.pop_back();
        return res;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends