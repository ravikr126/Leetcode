// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
 long long getnumber(long long num)
   {
            string s=to_string(num);
         int sz=s.size();
         int i=sz/2 -1,j=sz/2;
         if(sz%2!=0)i++;
         while(j<sz)
         {
             s[j]=s[i];j++;i--;
         }
         return stoll(s);
   }
long long int closestPalindrome(long long int num){
         long long ans=getnumber(num);
         long long gap=abs(ans-num);
         for(int i=0;i<15;i++)
         {
             long long z=pow(10,i);
             if(num-z>0)
             {
                 long long temp=getnumber(num-z);
                 if(gap>=abs(temp-num))
                 {
                     if(gap==abs(temp-num))ans=min(ans,temp);
                     else ans=temp;
                 }
             }
             long long maxx=1e15;
             if(num+z<maxx)
             {
                 long long temp=getnumber(num+z);
                 if(gap>=abs(temp-num))
                 {
                     if(gap==abs(temp-num))ans=min(ans,temp);
                     else ans=temp;
                 } 
             }
         }
         return ans;
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends