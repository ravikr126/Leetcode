class Solution {
public:
    string breakPalindrome(string &palindrome) {
        int n = palindrome.length();
        if(n == 1) return "";  // If string has only character return the empty string.
        int i = 0;
        for (;i < n; i++)
        {
            if(palindrome[i] != 'a')            /*Findind the first number which is not 'a',
												replacing it with 'a' (to get lexicographically smallest string.*/
            {
                if(n%2 == 1 && i == n/2) continue; /*but keep in mind that if the number which is not 'a' and is in the middle of the string with odd length, 
										then even after replacing that charachter string will be palindrome, so we will have to replace next non-'a' char.  */
                 else
                {
                    palindrome[i] = 'a';
                    return palindrome;
                }
            }
        }
        palindrome[i-1] = 'b'; // if all of the char in the string is 'a' then last char should be replaced by 'b'.
        return palindrome;
    }
};