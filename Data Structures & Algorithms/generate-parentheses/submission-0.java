class Solution {
    void ComputeAllParenthesis(int open, int close, int n, String s, List<String> allparentheses) {
        if(open == n) {
            for(int i=close ; i<n ; i++)
            s += ")";

            close = n;
        }

        if(open==n && close==n) {
            allparentheses.add(s);
            return ;
        }

        s += "(";
        ComputeAllParenthesis(open+1, close, n, s, allparentheses);
        s = s.substring(0, s.length() - 1);

        if(open > close) {
            s += ")";
            ComputeAllParenthesis(open, close+1, n, s, allparentheses);
            s = s.substring(0, s.length() - 1);
        }
    }

    public List<String> generateParenthesis(int n) {
        String s = "";
        List<String> allparentheses = new ArrayList<>();

        ComputeAllParenthesis(0, 0, n, s, allparentheses);

        return allparentheses;
    }
}
