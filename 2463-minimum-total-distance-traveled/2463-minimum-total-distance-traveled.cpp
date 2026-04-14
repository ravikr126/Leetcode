class Solution {
public:
    vector<vector<long long>> dp;

    long long solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();

        // all robots assigned
        if (i == n) return 0;

        // no factory left
        if (j == m) return 1e15;

        if (dp[i][j] != -1) return dp[i][j];

        long long res = solve(i, j + 1, robot, factory); // skip factory

        long long cost = 0;
        int pos = factory[j][0];
        int limit = factory[j][1];

        // assign k robots
        for (int k = 0; k < limit && i + k < n; k++) {
            cost += abs(robot[i + k] - pos);
            res = min(res, cost + solve(i + k + 1, j + 1, robot, factory));
        }

        return dp[i][j] = res;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        dp.assign(n, vector<long long>(m, -1));

        return solve(0, 0, robot, factory);
    }
};