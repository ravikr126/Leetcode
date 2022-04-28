// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // Write Your Code here
        int maxi=0;
        int mini=0;
        sort(candies,candies+N);
        int i=0;
        int j=N;
        while(i<j)
        {
            mini+=candies[i];
            j-=k;
            i++;
            
        }
        i=-1;
        j=N-1;
         while(i<j){
            maxi+=candies[j];
            i+=k;
            j--;
        }
        vector<int> v;
        v.push_back(mini);
        v.push_back(maxi);
        return v;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends