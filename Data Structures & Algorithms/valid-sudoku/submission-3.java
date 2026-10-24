class Solution {
    int [][]allSubSquaresIndexingData  =  {
        {0, 2, 0, 2}, 
        {0, 2, 3, 5},
        {0, 2, 6, 8},

        {3, 5, 0, 2}, 
        {3, 5, 3, 5},
        {3, 5, 6, 8},

        {6, 8, 0, 2}, 
        {6, 8, 3, 5},
        {6, 8, 6, 8}
    };

    boolean OutOfBound(int row, int col) {
        return (row<0 || row>=9 || col<0 || col>=9);
    }

    int [][]FindNextCell(int row, int col) {
        if(col+1 < 9)
            return new int[][]{{row}, {col+1}};

        return new int[][]{{row+1}, {0}};
    }

    boolean IsValidForRow(int value, int row, int col, char[][] board) {
        for(int j=0 ; j<9 ; j++) {
            if(j == col)
            continue;

            if(board[row][j] == String.valueOf(value).toCharArray()[0])
            return false;
        }

        return true;
    }

    boolean IsValidForCol(int value, int row, int col, char[][] board) {
        for(int i=0 ; i<9 ; i++) {
            if(i == row)
            continue;

            if(board[i][col] == String.valueOf(value).toCharArray()[0])
            return false;
        }

        return true;
    }

    int FindSubSquareIndex(int row, int col) {
        for(int i=0 ; i<allSubSquaresIndexingData.length ; i++) {
            if(row >= allSubSquaresIndexingData[i][0] && row<=allSubSquaresIndexingData[i][1] && col>=allSubSquaresIndexingData[i][2] && col<=allSubSquaresIndexingData[i][3])
            return i;
        }

        return -1;
    }

    boolean IsValidForSubSqaure(int value, int row, int col, char[][] board) {
        int currSubSquareIndex = FindSubSquareIndex(row, col);

        for(int i=allSubSquaresIndexingData[currSubSquareIndex][0] ; i<=allSubSquaresIndexingData[currSubSquareIndex][1] ; i++) {
            for(int j=allSubSquaresIndexingData[currSubSquareIndex][2] ; j<=allSubSquaresIndexingData[currSubSquareIndex][3] ; j++) {
                if(row==i && col==j)
                continue;

                if(board[i][j] == String.valueOf(value).toCharArray()[0])
                return false;
            }
        }

        return true;
    }

    boolean IsValid(int value, int row, int col, char[][] board) {
        if(!IsValidForRow(value, row, col, board))
            return false;

        if(!IsValidForCol(value, row, col, board))
            return false;

        return IsValidForSubSqaure(value, row, col, board);
    }

    boolean ComputeAllPossibilities(int row, int col, char[][] board) {
        if(OutOfBound(row, col)) {
            return true;
        }

        int [][]nextCell = FindNextCell(row, col);

        int nextRow = nextCell[0][0];
        int nextCol = nextCell[1][0];

        if(board[row][col] != '.') {
            if(IsValid(board[row][col]-'0', row, col, board))
            {
                return ComputeAllPossibilities(nextRow, nextCol, board);
            }
            else
                return false;
        }
        
        return ComputeAllPossibilities(nextRow, nextCol, board);
    }

    public boolean isValidSudoku(char[][] board) {
        return ComputeAllPossibilities(0, 0, board);
    }
}
