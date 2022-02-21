class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
           vector<int>cnt(n,0);
        vector<vector<int>>direct(n,vector<int>(n,0));
        
        for(int i=0;i<roads.size();i++){
            cnt[roads[i][0]]++;
            cnt[roads[i][1]]++;
            direct[roads[i][0]][roads[i][1]]=1;
            direct[roads[i][1]][roads[i][0]]=1;
        }
        int ans=0;
        for(int i=0;i<direct.size();i++){
            for(int j=0;j<direct.size();j++){
                if(i!=j){
                    int k=cnt[i]+cnt[j]-direct[i][j];
                    ans=max(ans,k);
                }
            }
        }
        return ans;
    }
};