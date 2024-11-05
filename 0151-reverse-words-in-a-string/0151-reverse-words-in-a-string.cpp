class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string a="";
        for(auto it:s){
            if(it!=' '){
                a+=it;
            }else{
                if(a.size()!=0){
                    st.push(a);
                    a="";
                }
            }
        }
        if(!a.empty()){
        st.push(a);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            ans+=" ";
            st.pop();
        }
        ans.erase(ans.end()-1);//earsing the last un-necessary space
        return ans;
    }
};