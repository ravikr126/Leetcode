// { Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}

// } Driver Code Ends


long long int calculate(int a[], int n)
{
    // Complete the function
   sort(a, a + n);
 
    int count = 1;
    int answer = 0;
 
    // Traversing through the
    // elements
    for (int i = 1; i < n; i++) {
     
        if (a[i] == a[i - 1]){
 
            // Counting frequency of each
            // elements
            count += 1;
             
        }
        else
        {
            // Adding the contribution of
            // the frequency to the answer
            answer = answer + (count * (count - 1)) / 2;
            count = 1;
        }
    }
 
    answer = answer + (count * (count - 1)) / 2;
 
    return answer;

}
