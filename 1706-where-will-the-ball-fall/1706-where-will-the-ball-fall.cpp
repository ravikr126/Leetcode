class Solution 
{
public:
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
                                             
        // [1] lambda-function that simulates m steps
        auto move_ball = [&](int j) -> int
        {
            for (int i = 0; i < m; ++i)
            {
                int k = j + grid[i][j];
                if (k < 0 || k >= n || grid[i][j] != grid[i][k])
                    return -1;
                j = k;
            }
            return j;
        };
                                     
        // [2] move n balls from the top to the bottom
        vector<int> pos;
        for (int j = 0; j < n; ++j) pos.push_back(move_ball(j));

        return pos;
    }
};