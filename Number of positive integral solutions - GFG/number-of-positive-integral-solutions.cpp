// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long factorial(int n){
        long fact = 1;
        for(int i = 1; i <= n; i++){
            fact = fact*i;
        }
        return fact;
    }
    
    long posIntSol(string s){
        int n = 1, index = 0;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == '+') n++;
            if(s[j] == '=') index = j;
        }
        string num = s.substr(index + 1);
        int k = stoi(num);
        k--;
        n--;
        
        long long val1 = 1;
        for(int j = 0; j < n; j++){
            val1 *= (k);
            k--;
        }
        long long val2 = factorial(n);
        long ans = val1/val2;
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends