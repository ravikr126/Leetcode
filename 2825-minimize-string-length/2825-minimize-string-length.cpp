class Solution {
public:
    int minimizedStringLength(string s) {
        set<int> box;
        for(auto it: s){
            box.insert(it);
        }
        return box.size();
    }
};