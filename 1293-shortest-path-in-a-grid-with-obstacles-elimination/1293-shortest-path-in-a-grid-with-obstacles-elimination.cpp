class Solution {
public:
    int shortestPath(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        if(n == 1 && m == 1)
            return 0;
        vector<vector<int>> vis(n, vector<int> (m, -1));

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        // To check whether cell lies in within matrix or not.
        auto check = [&](int x, int y) {
            return x > -1 && x < n && y > -1 && y < m;
        };

        queue<vector<int>> q;
        // {row, col, no: of towns visited, coins left}
        q.push({0, 0, 0, k});
        // For first cell, k coins are left.
        vis[0][0] = k;
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            int row = t[0], col = t[1], towns = t[2], coins = t[3];

            if(row == n - 1 && col == m - 1) // Reached destination
                return towns;
            
            // If we reach a town with toll plaza. If no coins left, we continue, else decrement coins.
            if(a[row][col] == 1) {
                if(!coins)
                    continue;
                coins--;
            }
            // Checking adjacent cells
            for(auto [dx, dy]: dir) {
                int x = row + dx;
                int y = col + dy;
                // If cell lies in matrix, and has either not been visited, or visited wih less number of coins, we can push the cell in queue.
                if(check(x, y) && (vis[x][y] < coins)) {
                    vis[x][y] = coins;
                    q.push({x, y, towns + 1, coins});
                }
            }
        }

        // In case we don't reach destination, return -1.
        return -1;
    }
};