// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// ranges[i][0] is the start of ith range
// ranges[i][1] is the end of ith range
bool cmp(vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}
class Solution{
public:
    int max_non_overlapping( vector< vector<int> >& r )
    {
        sort(r.begin(),r.end(),cmp);
        int count=1;
        int end=r[0][1];
        for(int i=1;i<r.size();i++){
            if(r[i][0]>=end){
                end=r[i][1];
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		vector< vector<int> > v(n,vector<int>(2));
		for(int i=0; i<n; i++)
			cin>> v[i][0] >> v[i][1];
			
        Solution ob;
		cout<< ob.max_non_overlapping(v) << endl;
	}
	return 1;
}

  // } Driver Code Ends