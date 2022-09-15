// Time Complexity: O(N + KlogK)
// Space Complexity: O(N)
// where N is the number of elements in `changed` 
// and K is the number of unqiue elements in `changed`
class Solution {
public:
    // hashmap approach
    vector<int> findOriginalArray(vector<int>& changed) {
        // if the length of the input is odd, then return {}
        // because doubled array must have even length
        if (changed.size() & 1) return {};
        // count the frequency of each number
        unordered_map<int, int> m;
        for (auto x: changed) m[x]++;
        vector<int> ans;
        // sort in ascending order
        sort(changed.begin(), changed.end());
        // keep the unique elements only in changed
        // think of test cases like [0,0,0,0]
        // alternatively you can handle it like
        // - check if the frequency of 0 is odd, if so, return {}
        // - push `0` `m[0] / 2` times to ans
        changed.erase(unique(changed.begin(), changed.end()), changed.end());
        // so that we can iterate `changed` from smallest to largest
        for (auto x : changed) {
            // if the number of m[x] is greater than than m[x * 2]
            // then there would be some m[x] left
            // therefore, return {} here as changed is not a doubled array
            if (m[x] > m[x * 2]) return {};
            for (int i = 0; i < m[x]; i++) {
                // otherwise, we put the element `x` `m[x]` to ans
                ans.push_back(x);
                // at the same time we decrease the count of m[x * 2] by 1
                // we don't need to decrease m[x] by 1 as we won't use it again
                m[x * 2] -= 1;
            }
        }
        return ans;
    }
};