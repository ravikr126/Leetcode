class Solution {
public:
    int minLengthAfterRemovals(string s) {
        unordered_map<char, int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        return abs(mp['a']-mp['b']);
    }
};