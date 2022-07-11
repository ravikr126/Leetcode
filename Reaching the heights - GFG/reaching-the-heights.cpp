// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    vector<int>ans(n);
   sort(a,a+n);
  
  int i=0;
  int s=0;int e=n-1;
  int up=0;
  int down=0;
  //used zero base indexing
  while(s<=e)
  {
      if(i&1)
      {
          ans[i]=a[s++];
          down+=ans[i];
      }else{
          ans[i]=a[e--];
          up+=ans[i];
      }
      i++;
  }
  if(up>down)
  {
      return ans;
  }
  return {-1};

}
