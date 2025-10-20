class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int x = 0;
        for (int i = 0; i < n; i++) {
            bool found = operations[i].find("+") != string::npos;
            if (found) x++;
            else x--;
        }
        return x;
    }
};