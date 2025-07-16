class Solution {
public:
    int maxDepth(string s) {
        int result=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                result=max(result,count);
            }
            if(s[i]==')'){
                count--;
            }
        }
        return result;
    }
};