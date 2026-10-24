class Solution {
public:
    vector<vector<int>> allSubSquaresIndexingData =  {
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

    bool OutOfBound(int row, int col) {
        return (row<0 || row>=9 || col<0 || col>=9);
    }

    pair<int, int> FindNextCell(int row, int col) {
        if(col+1 < 9)
            return {row, col+1};

        return {row+1, 0};
    }

    bool IsValidForRow(int value, int row, int col, vector<vector<char>>& board) {
        for(int j=0 ; j<9 ; j++) {
            if(j == col)
                continue;
            
            if(board[row][j] == (value+'0'))
                return false;
        }

        return true;
    }

    bool IsValidForCol(int value, int row, int col, vector<vector<char>>& board) {
        for(int i=0 ; i<9 ; i++) {
            if(i == row)
                continue;

            if(board[i][col] == (value+'0'))
                return false;
        }

        return true;
    }

    int FindSubSquareIndex(int row, int col) {
        for(int i=0 ; i<allSubSquaresIndexingData.size() ; i++) {
            if(row>=allSubSquaresIndexingData[i][0] && row<=allSubSquaresIndexingData[i][1] && col>=allSubSquaresIndexingData[i][2] && col<=allSubSquaresIndexingData[i][3])
                return i;
        }

        return -1;
    }

    bool IsValidForSubSqaure(int value, int row, int col, vector<vector<char>>& board) {
        int currSubSquareIndex = FindSubSquareIndex(row, col);

        for(int i=allSubSquaresIndexingData[currSubSquareIndex][0] ; i<=allSubSquaresIndexingData[currSubSquareIndex][1] ; i++) {
            for(int j=allSubSquaresIndexingData[currSubSquareIndex][2] ; j<=allSubSquaresIndexingData[currSubSquareIndex][3] ; j++) {
                if(row==i && col==j)
                    continue;
                
                if(board[i][j] == (value+'0'))
                    return false;
            }
        }

        return true;
    }

    bool IsValid(int value, int row, int col, vector<vector<char>>& board) {
        if(!IsValidForRow(value, row, col, board))
            return false;

        if(!IsValidForCol(value, row, col, board))
            return false;

        return IsValidForSubSqaure(value, row, col, board);
    }

    bool ComputeAllPossibilities(int row, int col, vector<vector<char>>& board) {
        if(OutOfBound(row, col)) {
            return true;
        }

        pair<int, int> nextCell = FindNextCell(row, col);
        int nextRow = nextCell.first;
        int nextCol = nextCell.second;

        if(board[row][col] != '.') 
        {
            if(IsValid(board[row][col]-'0', row, col, board))
            {
                return ComputeAllPossibilities(nextRow, nextCol, board);
            }
            else
                return false;
        }
        else {
            return ComputeAllPossibilities(nextRow, nextCol, board);
        }

        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return ComputeAllPossibilities(0, 0, board);
    }
};
