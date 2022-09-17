class Solution {
public:
    // DFS traversal until we found the 1 in grid
    void dfs(int i, int j, vector<vector<int>>& grid){
        int r = grid.size();
        int c = grid[0].size();
        if( i < 0 || i>= r || j < 0 || j >= c || grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        
        
        // For 1st and last row check if 1 is present or not
        // If 1 is present do traversal call and mark them as zero
        for(int i = 0; i < c; i++){
            // 0 , i
            // r-1 , i
            
            dfs(0,i,grid);
            dfs(r-1,i,grid);
        }
        // For 1st and last column check if 1 is present or not
        // If 1 is present do traversal call and mark them as zero
        for(int i = 0; i < r; i++){
            // i , 0
            // i , c-1
            dfs(i,0,grid);
            dfs(i, c-1, grid);
        }
        
        // All grid for which we can walk to boundary are marked as zero by above
        // two for loops. Not remaining are the one which are required for final answer
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};