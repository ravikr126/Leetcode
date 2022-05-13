// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int a1[], int a2[], int n) {
            // code here
           set<int> s;
        for(int i=0;i<n;i++){
            s.insert(a2[i]);
            s.insert(a1[i]);
        }
        while(s.size()>n){
            s.erase(s.begin());
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(s.find(a2[i])!=s.end()){
                ans.push_back(a2[i]);
                s.erase(a2[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(s.find(a1[i])!=s.end()){
                ans.push_back(a1[i]);
                s.erase(a1[i]);
            }
        }
        return ans;
                       
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends