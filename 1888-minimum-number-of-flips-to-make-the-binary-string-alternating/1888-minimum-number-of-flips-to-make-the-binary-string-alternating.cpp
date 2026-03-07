class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s=s+s;
        int flip1=0;
        int flip2=0;
        string s1,s2;
        int result=INT_MAX;
//s1=10101010
// s2=01010101
        for(int i=0;i<2*n;i++){
            s1+= (i%2==0?'1':'0');
            s2+= (i%2==0?'0':'1');
        }

        int i=0,j=0;
         for(int j = 0; j < 2*n; j++){
            if(s[j]!=s1[j]) flip1++;
            if(s[j]!=s2[j]) flip2++;
            if(j-i+1>n){
               if(s[i]!=s1[i]) flip1--;
               if(s[i]!=s2[i]) flip2--;
               i++;
            }

            if(j-i+1==n){
                result= min({result, flip1,flip2}); 
            }
        

        }
        return result;
    }
};