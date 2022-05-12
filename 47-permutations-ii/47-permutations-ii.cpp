class Solution {
    string makeKey(vector<int>& path) {
        string key = "";
        for(int x : path) {
            key += to_string(x) + ':';
        }
        return key;
    }
    
    void bt(vector<int>& nums, unordered_set<int>& seen, vector<int>& path, vector<vector<int>>& ans, unordered_set<string>& uniques) {
        if(path.size() == nums.size()) {
            string key = makeKey(path);
            if(uniques.find(key) != uniques.end()) return;
            uniques.insert(key);
            ans.push_back(path);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(seen.find(i) != seen.end()) continue;
            seen.insert(i);
            path.push_back(nums[i]);
            bt(nums, seen, path, ans, uniques);
            seen.erase(i);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<string> uniques;
        unordered_set<int> seen;
        vector<int> path;
        vector<vector<int>> ans;
        bt(nums, seen, path, ans, uniques);
        return ans;
    }
};