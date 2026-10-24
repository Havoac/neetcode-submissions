class Solution {
public:
    bool IsOpeningBracket(char ch) {
        return (ch=='(' || ch=='{' || ch=='[');
    }

    bool HasOpeningBracketInStack(char ch, stack<char> &st) {
        if(st.empty())
            return false;
    
        if(ch==')' && st.top()=='(')
        return true;

        if(ch=='}' && st.top()=='{')
        return true;

        if(ch==']' && st.top()=='[')
        return true;

        return false;
    }

    bool isValid(string s) {
        stack<char> st;

        for(char ch:s) {
            if(IsOpeningBracket(ch))
                st.push(ch);
            else {
                if(HasOpeningBracketInStack(ch, st))
                    st.pop();
                else
                    return false;
            }
        }

        if(st.empty())
            return true;

        return (!IsOpeningBracket(st.top()));
    }
};
