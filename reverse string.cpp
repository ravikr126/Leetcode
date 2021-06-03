class Solution
{
    void helper(vector<char> &s s, int left, int right)
    {
        if (left >= right)
            return;
        char tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
        helper(s, left, right);
    }

    void reverseString(vector<char> &s)
    {
        helper(s, 0, s.length - 1);
    }
}