// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
        // Your code goes here 
        for(int i = 0; i < n - 1; i++){
            double low = magnets[i], high = magnets[i + 1];
            while((high - low) >= 0.000001){
                double mid = low + (high - low)/2;
                double p = 0;
                for(int k = 0; k < n; k++){
                    if(k <= i){
                        p += (double)1/(mid - magnets[k]);
                    }
                    else{
                        p -= (double)1/(magnets[k] - mid);
                    }
                }
                if(p >= (double)0){
                    low = mid;
                }
                else{
                    high = mid;
                }
            }
            getAnswer[i] = high;
        }
    
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
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends