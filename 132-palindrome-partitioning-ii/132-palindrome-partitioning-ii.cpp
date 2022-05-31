class Solution {
public:
   int minCut(std::string &s, int idx,
              std::vector<int> &dp,
              std::vector<std::vector<bool>> &pdp) {
        if (idx == s.length()) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int cuts = INT_MAX - 1;
        for (int k = idx; k < s.length(); k++) {
            if (pdp[idx][k]) {
                cuts = std::min(cuts, minCut(s, k + 1, dp, pdp) + 1);
            }
        }
        dp[idx] = cuts;
        return dp[idx];
    }
    
    void palindromeSubStrings(string &s,
                          std::vector<std::vector<bool>> &pdp) {
        for (int x = 0; x < s.length(); x++) {
            pdp[x][x] = true;
        }
        for (int x = 1; x < s.length(); x++) {
            if (s[x - 1] == s[x]) {
                pdp[x - 1][x] = true;
            }
        }
        for (int len = 2; len < s.length(); len++) {
            for (int x = 0, y = len; y < s.length(); x++, y++) {
                if (s[x] == s[y] and pdp[x + 1][y - 1] == true) {
                    pdp[x][y] = true;
                }
            }
        }
    }
    
    int minCut(string s) {
        std::vector<int> dp(s.length() + 1, -1);
        std::vector<std::vector<bool>> pdp(s.length(), std::vector<bool>(s.length(), false));
        palindromeSubStrings(s, pdp);
        return minCut(s, 0, dp, pdp) - 1;
    }
};