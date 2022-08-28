class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
           int n = mat.size();
        
        int m = mat[0].size();
        
        // sort the diagonal which is starting from first col
        
        for(int i = 0; i < n; i++)
        {
            // push the elements of diagonal into arr
            
            int row = i;
            
            int col = 0;
            
            vector<int> arr;
            
            while(row < n && col < m)
            {
                arr.push_back(mat[row][col]);
                
                row++;
                
                col++;
            }
            
            // sort the arr
            
            sort(arr.begin(), arr.end());
            
            // start putting the elements from bottom to top in diagonal
            
            row--;
            
            col--;
            
            while(row >= 0 && col >= 0)
            {
                mat[row][col] = arr.back();
                
                arr.pop_back();
                
                row--;
                
                col--;
            }
        }
        
        // sort the diagonal which is starting from first row
        
        for(int i = 1; i < m; i++)
        {
            // push the elements of diagonal into arr
            
            int row = 0;
            
            int col = i;
            
            vector<int> arr;
            
            while(row < n && col < m)
            {
                arr.push_back(mat[row][col]);
                
                row++;
                
                col++;
            }
            
            // sort the arr
            
            sort(arr.begin(), arr.end());
            
            // start putting the elements from bottom to top in diagonal
            
            row--;
            
            col--;
            
            while(row >= 0 && col >= 0)
            {
                mat[row][col] = arr.back();
                
                arr.pop_back();
                
                row--;
                
                col--;
            }
        }
        
        return mat;
    }
};