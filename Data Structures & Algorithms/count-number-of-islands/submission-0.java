class Solution {
    List<List<Integer>> directions = new ArrayList<>();

    boolean IsOutOfBound(int i, int j, int m, int n) {
        return (i<0 || i==m || j<0 || j==n);
    }

    void DFSTraversal(int i, int j, char[][] grid) {
        int m=grid.length, n=grid[0].length;

        for(List<Integer> nextCell:directions) {
            int r = i+nextCell.get(0);
            int c = j+nextCell.get(1);

            if(IsOutOfBound(r, c, m, n)) 
                continue;

            if(grid[r][c] == '0')
                continue;

            grid[r][c] = '0';
            DFSTraversal(r, c, grid);   
        }        
    }

    public int numIslands(char[][] grid) {
        directions.add(new ArrayList<>(Arrays.asList(0, 1)));
        directions.add(new ArrayList<>(Arrays.asList(0, -1)));
        directions.add(new ArrayList<>(Arrays.asList(1, 0)));
        directions.add(new ArrayList<>(Arrays.asList(-1, 0)));

        int m=grid.length, n=grid[0].length, islandCount =0;

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '0';
                    DFSTraversal(i, j, grid);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }
}
