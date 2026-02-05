class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& A) {
        int n = A.size();
        
        vector<int> res;
        for (int i = 0; i < n; i++)
            res.push_back(A[(((i + A[i]) % n) + n) % n]);

        return res;
    }
};