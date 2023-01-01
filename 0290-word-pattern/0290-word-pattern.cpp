class Solution {

string findWord(string &str,int &index){
    string word = "";
    while(index < str.length() && str[index] != ' '){
        word.push_back(str[index]);
        index++;
    }
    index++;
    return word;
}

public:
    bool wordPattern(string pattern, string s) {
        map<char,string> mp;
        unordered_map<string,char> mp2;
        int index = 0;
        for(int i=0;i<pattern.length();i++){
            if(index >= s.length())
                return false;
            char ch = pattern[i];
            string word = findWord(s,index);
           
            if(mp.find(ch) == mp.end()){
                mp[ch] = word; 
            }   
            else if(mp[ch] != word){
                return false;  
            } 
        } 
        if(index < s.length()) 
            return false;


        for(auto p:mp){
            if(mp2.find(p.second) == mp2.end())
                mp2[p.second] = p.first;
            else if(mp2[p.second] != p.first)
                return false;

        }
        return true;

       
    }
};