class Solution {
    boolean IsValidPosition(int col, int row, int n, List<String> validCombination) {
        // Vertical
        for(int i=0 ; i<row ; i++) {
            if(validCombination.get(i).charAt(col) == 'Q')
                return false;
        }

        int i=row-1, j=col-1;

        // Left Diagonal
        while(i>=0 && j>=0) {
            if(validCombination.get(i).charAt(j) == 'Q')
            return false;

            i--;
            j--;
        }

        // Right Diagonal
        i=row-1;
        j=col+1;
        while(i>=0 && j<n) {
            if(validCombination.get(i).charAt(j) == 'Q')
            return false;

            i--;
            j++;
        }

        return true;
    }

    void Traverse(int i, int n, List<String> validCombination, List<List<String>> ans) {
        if(i == n) {
            ans.add(new ArrayList<>(validCombination));
            return ;
        }

        StringBuilder validRow = new StringBuilder("");

        for(int j=0 ; j<n ; j++) {
            validRow.append('.');
        }

        for(int j=0 ; j<n ; j++) {
            if(!IsValidPosition(j, i, n, validCombination)) 
            continue;

            validRow.setCharAt(j,'Q');
            validCombination.add(validRow.toString());

            Traverse(i+1, n, validCombination, ans);

            validRow.setCharAt(j,'.');
            validCombination.remove(validCombination.size()-1);
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();

        List<String> validCombination = new ArrayList<>();

        Traverse(0, n, validCombination, ans);

        return ans;
    }
}
