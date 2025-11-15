class Solution {
public:
    int numberOfSubstrings(const string &s) {
    int res = 0;
    for (int z = 0; z + z * z <= s.size(); ++z) {
        int cnt[2] = {}, p = 0, old_res = res;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            ++cnt[s[i] == '1'];
            while (cnt[0] > z)
                --cnt[s[j++] == '1'];
            if (cnt[0] == z && cnt[1] && cnt[1] >= z * z) {
                for (p = max(p, j); p < i && s[p] == '1'; ++p);
                res += 1 + min(p - j, cnt[1] - z * z);              
            }
        }
        if (res == old_res)
            break;
    }
    return res;
}
};