//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    stack<char>st;
    
    int cnt=0;
    int n=num.size();
    for(int j=0 ; j<n ; j++){
        char ch=num[j];
        
        while(!st.empty() and st.top()-'0' > ch-'0' and cnt < k){
            st.pop();
            cnt++;
        }
        
        st.push(ch);
       
    }
    
    
    
    while(cnt < k and !st.empty()){
        st.pop();
        cnt++;
    }
    
    string ans="";
    while(!st.empty()){
        char ch=st.top();
        st.pop();
        ans.push_back(ch);
    }
    
    while(ans.back() == '0'){
        ans.pop_back();
    }
    
    if(ans.empty()){
        return "0";
    }
    reverse(ans.begin(), ans.end());
    
    return ans;
}