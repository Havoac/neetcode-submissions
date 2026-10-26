class Solution {
    boolean IsOutOfBound(int i, int j, int m, int n) {
        return (i<0 || i==m || j<0 || j==n);
    }

    public int orangesRotting(int[][] grid) {
        int [][]directions = new int[4][2];

        directions[0][0] = 1;
        directions[0][1] = 0;

        directions[1][0] = -1;
        directions[1][1] = 0;

        directions[2][0] = 0;
        directions[2][1] = 1;

        directions[3][0] = 0;
        directions[3][1] = -1;

        Queue<int []> q = new LinkedList<>();
        int m=grid.length, n=grid[0].length;

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == 2)
                q.add(new int[]{i, j});
            }
        }

        int ans = 0;

        while(!q.isEmpty()) {
            boolean canRot = false;
            int size = q.size();

            for(int k=0 ; k<size ; k++) {
                int []cell=q.poll();
                int i=cell[0], j=cell[1];

                for(int []movement:directions) {
                    int r = i+movement[0];
                    int c = j+movement[1];
                
                    if(IsOutOfBound(r, c, m, n)) 
                    continue;
                    
                    if(grid[r][c] != 1)
                    continue;

                    canRot = true;
                    grid[r][c] = 2;
                    q.add(new int[]{r, c});
                }
            }

            if(canRot)
            ans++;
        }

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == 1)
                return -1;
            }
        }

        return ans;
    }
}
