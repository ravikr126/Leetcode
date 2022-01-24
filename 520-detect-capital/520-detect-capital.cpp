class Solution {
public:
    bool detectCapitalUse(string word) {
    //     for(int i=1;i<word.size();i++){
    //         if( (isupper(word[1]) != isupper(word[i]))  ||  (islower(word[0]) && isupper(word[i])) )
    //             return false;
    //     }
    //     return true;
    // 
    
     int flag = 0, FLAG = 0;
        
        for(int i = 1; i < word.size(); i++)
        {
            if(word[i] >= 'A' && word[i] <= 'Z')
                FLAG = 1;
            if(word[i] >= 'a' && word[i] <= 'z')
                flag = 1;
        }
        
        if(flag && FLAG)
            return 0;
        if(FLAG && word[0] >= 'a' && word[0] <= 'z')
            return 0;
        return 1;
    
    
    
    
    }
    
};