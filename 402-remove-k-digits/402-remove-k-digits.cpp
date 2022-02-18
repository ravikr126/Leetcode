class Solution {
public:
    string removeKdigits(string num, int k) {
    string ans="";
        
        for(auto it:num){
            while(ans.size()!=0 and ans.back()>it and k!=0){
                ans.pop_back();
                k--;
            }
            
            if(ans.size()!=0 or it!='0'){
                ans.push_back(it);
            }
        }
        
        while(ans.length()!=0 and k--){
            ans.pop_back();
        }
        
        return ans.empty()?"0":ans;
    }
};