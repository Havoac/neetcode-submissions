class Solution {
    int [][]directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    private boolean IsOutOfBound(int i, int j, int m, int n) {
        return (i<0 || i==m || j<0 || j==n);
    }

    private boolean IsAtBoundary(int i, int j, int m, int n) {
        return (i==0 || i==m-1 || j==0 || j==n-1);
    }

    private void Mark(int i, int j, char[][] board, boolean[][] shouldBeConverted) {
        int m=board.length, n=board[0].length;

        shouldBeConverted[i][j] = false;
        
        for(int []direction:directions) {
            int nr = i+direction[0];
            int nc = j+direction[1];
        
            if(IsOutOfBound(nr, nc, m, n)) 
                continue;
            
            if(shouldBeConverted[nr][nc] == false)
                continue;

            Mark(nr, nc, board, shouldBeConverted);
        }
    }

    public void solve(char[][] board) {
        int m=board.length, n=board[0].length;
        boolean [][]visited = new boolean[m][n];

        List<List<Integer>> boundaryCells = new ArrayList<>();
        boolean [][]shouldBeConverted = new boolean[m][n];

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(board[i][j] == 'O')
                    shouldBeConverted[i][j] = true;
            }
        }

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(IsAtBoundary(i, j, m, n) && board[i][j] == 'O') 
                    boundaryCells.add(new ArrayList<>(Arrays.asList(i, j)));
            }
        }

        for(List<Integer> cell:boundaryCells) {
            int i = cell.get(0);
            int j = cell.get(1);

            if(board[i][j]=='O')
                Mark(i, j, board, shouldBeConverted);
        }

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(shouldBeConverted[i][j])
                board[i][j] = 'X';
            }
        }
    }
}
