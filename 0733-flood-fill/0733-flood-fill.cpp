class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,int val, int color){
        if(val<0 || sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc] == color || image[sr][sc] != val)
            return;
        image[sr][sc]=color;
        dfs(image, sr-1,sc, val, color);
        dfs(image, sr,sc-1, val, color);
        dfs(image, sr+1,sc, val, color);
        dfs(image, sr,sc+1, val, color);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val=image[sr][sc];
        dfs(image, sr,sc,val,color);
        return image;
    }
};