class Solution {
public:
    int minimizedStringLength(string s) {
        bool arr[26] = {false};
        int n = s.length(), count = 0;
        for(int i = 0; i < n; i++){
            if(!arr[s[i] - 'a']){
                arr[s[i] - 'a'] = true;
                count++;
            }
        }
        return count;
    }
};