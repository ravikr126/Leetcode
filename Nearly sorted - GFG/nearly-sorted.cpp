// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        // Your code here
         set<int> st;
        for(int i = 0; i < k; i++)
            st.insert(arr[i]);
        
        vector<int> res;
        for(int i = 0; i <= min(n - 1, n - k - 1); i++) {
            
            st.insert(arr[i + k]);
            int x = *(st.begin());
            res.push_back(x);
            st.erase(x);
        }
        
        for(auto x : st) res.push_back(x);
        return res;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends