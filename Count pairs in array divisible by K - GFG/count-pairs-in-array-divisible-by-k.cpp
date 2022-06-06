// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        long long count = 0;
       unordered_map<int, int> mp;
       for (int i = 0; i < n; i++) {
           if (A[i] % K == 0 && mp.count(0)) {
               count += mp[0];
           }
           else if (mp.count(K - A[i] % K)) {
               count += mp[K - A[i] % K];
           }
           mp[A[i] % K]++;
       }
       return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends