//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string s)
{
    // your code here
    unordered_map<char,int> mp;
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }
    
    int count=0;
    for(auto it :mp)
    {
        if(it.second%2==1)
        count++;
    }
    if(count>1)
    return 0;
    return 1;
}