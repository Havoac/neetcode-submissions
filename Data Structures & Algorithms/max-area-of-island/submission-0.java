class Solution {
    List<List<Integer>> directions = new ArrayList<>();

    boolean IsOutOfBound(int i, int j, int m, int n) {
        return (i<0 || i==m || j<0 || j==n);
    }

    int DFSTraversal(int i, int j, int[][] grid) {
        int m=grid.length, n=grid[0].length, ans=0;

        for(List<Integer> nextCell:directions) {
            int r = i+nextCell.get(0);
            int c = j+nextCell.get(1);

            if(IsOutOfBound(r, c, m, n)) 
                continue;

            if(grid[r][c] == 0)
                continue;

            grid[r][c] = 0;
            ans += 1 + DFSTraversal(r, c, grid);   
        }        

        return ans;
    }

    public int maxAreaOfIsland(int[][] grid) {
        directions.add(new ArrayList<>(Arrays.asList(0, 1)));
        directions.add(new ArrayList<>(Arrays.asList(0, -1)));
        directions.add(new ArrayList<>(Arrays.asList(1, 0)));
        directions.add(new ArrayList<>(Arrays.asList(-1, 0)));

        int m=grid.length, n=grid[0].length, maxAreaOfIsland = 0;

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    maxAreaOfIsland = Math.max(maxAreaOfIsland, 1+DFSTraversal(i, j, grid));
                }
            }
        }

        return maxAreaOfIsland;
    }
}
