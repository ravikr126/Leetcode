class Solution {
public:
     void solve(vector<int>&C,vector<int>&A,vector<vector<int>>&res,int target,int sum,int start)
    {
        if(sum == target)
        {
            res.push_back(A);
            return;
        }
        
        for(int i = start; i < C.size(); i++)
        {
            if(sum + C[i] <= target)
            {
                A.push_back(C[i]);
                sum += C[i];
                solve(C,A,res,target,sum,i);
                A.pop_back();
                sum -= C[i];
            }
        }
            
    }
    vector<vector<int>> combinationSum(vector<int>&C, int target) {
        vector<vector<int>>res;
        vector<int>A;
        solve(C,A,res,target,0,0);
        return res;
        
    }
};