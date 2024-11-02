class Solution {
public:
    bool isPalindrome(string s) {
     string str="";
    for (auto& x : s) { 
        x = tolower(x); 
    } 
     for(int i=0;i<s.size();i++){
        if(s[i]>96 && s[i]<123){
            str+=s[i];
        }
        if(s[i]>=47 && s[i]<58) str+=s[i];
     }

     int start=0;
     int end= str.size()-1;
     cout<<str<<endl;
     while(start<=end){
        if(str[start]!=str[end]){
            return false;
        }
        start++;
        end--;
     }
     return true;
    }
};