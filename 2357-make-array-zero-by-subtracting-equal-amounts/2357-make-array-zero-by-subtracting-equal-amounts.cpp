class Solution {
public:
    int minimumOperations(vector<int>& A) {
       
        unordered_set<int> s = unordered_set(A.begin(), A.end());
        return s.size() - s.count(0);
    }
};