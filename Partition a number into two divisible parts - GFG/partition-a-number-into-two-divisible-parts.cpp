// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string S, int a, int b){
        // code here 
        
            int n = S.length();
        for(int i=1;i<n;i++)
        {
            if(stoi(S.substr(0,i))%a==0
            &&stoi(S.substr(i,(n-i)))%b==0)
            {
                string ans=S.substr(0,i);
                ans+=" ";
                ans+=S.substr(i,(n-i));
                return ans;
            }
        }
        return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends