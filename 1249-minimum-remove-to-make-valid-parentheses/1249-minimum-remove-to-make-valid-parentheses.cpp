class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string res = "";

        for (int i = 0; i < s.length(); ++i)
        {
            // if we find open parenthesis push it to stack
            if (s[i] == '(')
                st.push(i);
            // if we find close parenthisis check
            // if there is a open parenthisis or the stack is empty
            else if (s[i] == ')')
            {
                // if stack  is empty then we need to remove that index from string
                // replacing it with '#' for our convenience
                if (st.empty())
                    s[i] = '#';
                else
                    // if there is an open parenthesis than remove that  from the stack
                    st.pop();
            }
        }

        // now , if stack is not empty that means it has open parenthesis
        // which have no closing parenthesis.
        // so we have to replace that index of string with '#' for our convenience
        while (!st.empty())
        {
            s[st.top()] = '#';
            st.pop();
        }

        // making the resultant string by excluding '#'
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != '#')
                res.push_back(s[i]);
        }

        return res; 
    }
};