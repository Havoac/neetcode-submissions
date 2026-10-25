class Solution {
    void ComputeAllParenthesis(int open, int close, int n, StringBuilder s, List<String> allparentheses) {
        if(open == n) {
            for(int i=close ; i<n ; i++)
                s.append(")");

            int toRemove = n-close;
            close = n;

            if(close==n) {
                allparentheses.add(s.toString());

                while(toRemove > 0) {
                    s.deleteCharAt(s.length() - 1);
                    toRemove--;
                }
                
                return ;
            }
        }

        s.append("(");
        ComputeAllParenthesis(open+1, close, n, s, allparentheses);
        s.deleteCharAt(s.length() - 1);

        if(open > close) {
            s.append(")");
            ComputeAllParenthesis(open, close+1, n, s, allparentheses);
            s.deleteCharAt(s.length() - 1);
        }
    }

    public List<String> generateParenthesis(int n) {
        StringBuilder s = new StringBuilder("");
        List<String> allparentheses = new ArrayList<>();

        ComputeAllParenthesis(0, 0, n, s, allparentheses);

        return allparentheses;
    }
}
