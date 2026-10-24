class Solution {
public:
    bool IsOperator(string s) {
        return (s=="+" || s=="-" || s=="*" || s=="/");
    }

    int ComputeTheFinalValue(int val1, int val2, string opera) {
        if(opera == "+")
        {
            return (val1+val2);
        }
        else if(opera == "-") {
            return (val1-val2);
        }
        else if(opera == "*") {
            return (val1*val2);
        }
        return (val1/val2);
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size(), ans=0;

        for(string s:tokens) {
            if(!IsOperator(s))
                st.push(stoi(s));
            else {
                if(st.size() >= 2) {
                    int val1 = st.top();
                    st.pop();
                    int val2 = st.top();
                    st.pop();

                    int finalValue = ComputeTheFinalValue(val2, val1, s);

                    st.push(finalValue);
                }
            }
        }

        return st.top();
    }
};
