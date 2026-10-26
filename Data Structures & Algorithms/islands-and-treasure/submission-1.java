class Solution {
    List<List<Integer>> directions = new ArrayList<>();
    int MAX_VAL = 2147483647;

    boolean IsOutOfBound(int i, int j, int m, int n) {
        return (i<0 || i==m || j<0 || j==n);
    }

    public void islandsAndTreasure(int[][] grid) {
        directions.add(new ArrayList<>(Arrays.asList(0, 1)));
        directions.add(new ArrayList<>(Arrays.asList(0, -1)));
        directions.add(new ArrayList<>(Arrays.asList(1, 0)));
        directions.add(new ArrayList<>(Arrays.asList(-1, 0)));

        int m=grid.length, n=grid[0].length;
        Queue<int []> q = new LinkedList<>();

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == 0)
                q.add(new int[]{i, j});
            }
        }

        while(!q.isEmpty()) {
            int []cell = q.poll();
            int i=cell[0], j=cell[1];

            for(List<Integer> nextCell:directions) {
                int r = i + nextCell.get(0);
                int c = j + nextCell.get(1);

                if(IsOutOfBound(r, c, m, n)) 
                    continue;

                if(grid[r][c] != MAX_VAL)
                    continue;

                grid[r][c] = 1 + grid[i][j];
                q.add(new int[]{r, c});
            } 
        }
    }
}
