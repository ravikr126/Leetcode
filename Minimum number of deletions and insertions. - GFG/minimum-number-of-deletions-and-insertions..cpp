//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int findLCS(string a, string b, int n1, int n2){
	    if(n1 == 0 || n2 == 0) 
	        return 0;
	   
	    if(a[n1-1] == b[n2-1]){
	        return 1 + findLCS(a,b, n1-1,n2-1);
	    }
	    return max(findLCS(a,b,n1,n2-1), findLCS(a,b,n1-1,n2));
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.length();
	    int m = str2.length();
	    int arr[n+1][m+1];
	    for(int i=0; i<=n;i++){
	        for(int j=0;j<=m;j++){
	            if(i == 0 || j == 0 ){
	                arr[i][j] = 0;
	                continue;
	            }else if(str1[i-1] == str2[j-1]){
	                arr[i][j] = 1 + arr[i-1][j-1];
	            }else {
	                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
	            }
	        }
	    }
	    //int lcs1 = findLCS(str1, str2, str1.length(), str2.length());
	    int lcs = arr[n][m];
	    
	    int deletion = str1.length() - lcs;
	    int insertion = str2.length() - lcs;
	    return insertion + deletion;
	    
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends