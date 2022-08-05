class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>v(n+1,vector<int>(n+1,0));
        vector<int> deg(n+1,0);
        for(int i=0;i<edges.size();i++)
        {
            vector<int>e=edges[i];
             v[e[0]][e[1]]=1;
             v[e[1]][e[0]]=1;
             deg[e[0]]++;
             deg[e[1]]++;
 }
 
 int res=INT_MAX;
 for(int i=1;i<n;i++)
 {
     for(int j=i+1;j<=n;j++)
     {
         for(int k=j+1;k<=n;k++)
         {
             if(v[i][j]==1 && v[j][k]==1 && v[k][i]==1)
             {
                 res=min(res,deg[i]+deg[j]+deg[k]-6);
             }
         }
     }
 }
        
 if(res==INT_MAX) return -1;
 return res;
 
    }
};