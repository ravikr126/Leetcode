class Solution {
public:
     
    //  suppose we have, aabb
    //                    aabb
    //        a|abb                        aa | bb 
    //
    //     a | a | bb                   aa|b|b  aa|bb|
    //
    //  a|a|b| b|      a|a|bb|        aa|b|b|
    
    // This is how partitioning will be done, we check the left side if it's palidrome, if // yes then we will store the left part and move to check right part recursively till we //don't come to end of the string. If we reach the end we store all the partitions as //answer
    

    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;
        
        vector<string> path;
        dfs(0, s, path, ret); //for recursive tree
        
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) { //If we reach to end, store all the partitions as answer
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) { // checking for each partition if its                                                     // palidrome or not
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);      //if left part if palidrome then recursively check for right part
                path.pop_back();             //remove the chosen element before moving back
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) { //to check palindrome
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};