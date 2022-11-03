class Solution {
public:
    int longestPalindrome(vector<string>& words) {
         int ans=0;
        bool odd=false;
        
        unordered_map<string,int>m;
        for(string&word:words){
            m[word]++;
        }
        
        for(int i=0;i<words.size();i++){
            string rev="";
            rev+=words[i][1];
            rev+=words[i][0];
            
            if(rev!=words[i]){
                if(m.count(rev)){
                    
                    ans+=(min(1,(min(m[rev],m[words[i]])))*4);
                    m[rev]>0?m[rev]--:true;
                    m[words[i]]>0?m[words[i]]--:true;
                     
                }
            }
            else{
                
                ans+=(m[rev]/2)*4;
                m[rev]%=2;
                if(m[rev]==1){
                    odd=true;
                }
                 
            }
        }
        
        odd?ans+=2:true;
        
        return ans ;
    }
};