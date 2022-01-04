class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
         if(str1.length()>str2.length()) {
          string res=str1;
          str1=str2;
          str2=res;
        }
       if(str1.length()==str2.length()) return (str1==str2?str1:"");
        
       for(int i=str1.length()-1;i>=0;i--){
          string p= str1.substr(0,i+1);
         string m;
         bool flag=0;
           while(m.length()<=str2.length()){
               m+=p;
             if(m.length()==str2.length() && m==str2) {flag=1; break;}
           }
         if(flag==0) continue;
          m.clear();
          while(m.length()<=str1.length()){
               m+=p;
             if(m.length()==str1.length() && m==str1){
                  return p;
             }
           }
         
       }
       return "";

    }
};