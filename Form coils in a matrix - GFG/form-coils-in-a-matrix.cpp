// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
   bool inBoard(int x, int y, int n)
   {
       if(x>=n || y>=n || x<0 || y<0) return 0;
       return 1;
   }
 
   vector<vector<int>> formCoils(int n) {
       
       // code here
       n = 4*n;
       vector<vector<int>> V;
       for(int i = 0;i<n;i++)
       {
           vector<int> tmp;
           for(int j = 0;j<n;j++)
           {
               tmp.push_back(-1);
           }
           V.push_back(tmp);
       }
       int cnt = 1;
       for(int i = 0;i<n;i++)
       {
           for(int j = 0;j<n;j++)
           {
               V[i][j]=cnt;
               cnt++;
           }
       }
       int XI = n/2 - 1;
       int YI = n/2;
       vector<int> ans1, ans2;
       vector<string> direction = {"down", "left", "up", "right"};
       int dir = 0;
       ans1.push_back(V[XI][YI]);
       int steps = 2;
       int incSteps = 0;
       while(V[XI][YI]!=1)
       {
           for(int i = 0;i<steps;i++)
           {
               if(V[XI][YI]==1) break;
               if(direction[dir]=="down") XI++;
               else if(direction[dir]=="left") YI--;
               else if(direction[dir]=="up") XI--;
               else if(direction[dir]=="right") YI++;
               if(inBoard(XI, YI, V.size())) ans1.push_back(V[XI][YI]);
           }
           dir = (dir+1)%4;
           incSteps++;
           if((incSteps%2)==0)steps=steps + 2;
       }
       XI = n/2;
       YI = n/2 - 1;
       direction = {"up", "right", "down", "left"};
       steps = 2;
       incSteps = 0;
       dir = 0;
       ans2.push_back(V[XI][YI]);
       while(V[XI][YI]!=n*n)
       {
           for(int i = 0;i<steps;i++)
           {
               if(V[XI][YI]==n*n) break;
               if(direction[dir]=="down") XI++;
               else if(direction[dir]=="left") YI--;
               else if(direction[dir]=="up") XI--;
               else if(direction[dir]=="right") YI++;
               if(inBoard(XI, YI, V.size())) ans2.push_back(V[XI][YI]);
           }
           dir = (dir+1)%4;
           incSteps++;
           if((incSteps%2)==0)steps=steps + 2;
       }
       V.clear();
       V.push_back(ans2);
       V.push_back(ans1);
       return V;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends