class Solution {
public:
    
//     l = left index
// r = right index
// t = top index
// b = bottom index
// d = direction

// if d = 0 then traverse left to right
// d = 1 then top to bottom
// d = 2 then right to left
// d = 3 then bottom to top
// And after every direction we are changing the value of index.
    
    
    vector<int> spiralOrder(vector<vector<int>>& mat) {
       int n = mat[0].size(),m = mat.size();
        int l = 0, r = n-1,t = 0,b = m-1,d = 0;
        vector<int> ans;
        while(t<=b && l<=r){
            if(d==0){
                for(int i=l;i<=r;++i) ans.push_back(mat[t][i]);
                t++;
                d = 1;
            }else if(d==1){
                for(int i=t;i<=b;++i) ans.push_back(mat[i][r]);
                r--;
                d = 2;
            }else if(d==2){
                for(int i=r;i>=l;--i) ans.push_back(mat[b][i]);
                b--;
                d=3;
            }else if (d==3){
                for(int i=b;i>=t;--i) ans.push_back(mat[i][l]);
                l++;
                d = 0;
            }
        }
        return ans;
    }
};