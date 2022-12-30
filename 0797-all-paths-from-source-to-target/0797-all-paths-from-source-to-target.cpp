class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, vector<int> &v, vector<vector<int>> &ans,int n)
    {
        v.push_back(node);
        if(node==n-1)
        {
            ans.push_back(v);
        }
        for(int i=0;i<graph[node].size();i++)
        {
            dfs(graph,graph[node][i],v,ans,n);
        }
        v.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v;
        vector<vector<int>> ans;
        int n=graph.size();
        dfs(graph,0,v,ans,n);
        return ans;
    }
};