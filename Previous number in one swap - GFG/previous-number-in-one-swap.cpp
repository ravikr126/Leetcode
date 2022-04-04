// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string previousNumber(string s){
        // code here 
        int i = s.size()-2;
        while(i>=0 and s[i]<=s[i+1]){
            i--;
        }
        if(i<0) return "-1";
        int j = s.size()-1;
        while(j>i and (s[i] <= s[j])){
            j--;
        }
        while(j>0 and s[j-1] == s[j]){
            j--;
        }
        
        swap(s[i], s[j]);
        if(s[0] == '0') return "-1";
        return s;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends