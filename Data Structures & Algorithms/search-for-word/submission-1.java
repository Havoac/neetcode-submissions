class Solution {
    List<List<Integer>> direction = new ArrayList<>();

    boolean IsOutOfBound(int i, int j, int m, int n) {
        return (i<0 || i==m || j<0 || j==n);
    }

    boolean DFS(int i, int j, int index, String word, boolean [][]visited, char[][] board) {
        int m=board.length, n=board[i].length, len=word.length();

        if(index == len)
            return true;

        for(int in=0 ; in<4 ; in++) {
            int r = i+direction.get(in).get(0);
            int c = j+direction.get(in).get(1);

            if(IsOutOfBound(r, c, m, n))
            continue;

            if(visited[r][c])
            continue;

            if(board[r][c]!=word.charAt(index))
            continue;

            visited[r][c] = true;

            if(DFS(r, c, index+1, word, visited, board))
                return true;

            visited[r][c] = false;
        }

        return false;
    }

    public boolean exist(char[][] board, String word) {
        int m=board.length, n=board[0].length;

        direction.add(new ArrayList<>(Arrays.asList(0, 1)));
        direction.add(new ArrayList<>(Arrays.asList(0, -1)));
        direction.add(new ArrayList<>(Arrays.asList(1, 0)));
        direction.add(new ArrayList<>(Arrays.asList(-1, 0)));

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(board[i][j] == word.charAt(0)) {
                    boolean [][]visited = new boolean[m][n];
                    visited[i][j] = true;

                    if(DFS(i, j, 1, word, visited, board))
                        return true;
                }
            }
        }

        return false;
    }
}
