class Solution {
public:
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
        
        for(int i = 0; i < c; i++){
            // 0 , i
            // r-1 , i
            
            dfs(0,i,grid);
            dfs(r-1,i,grid);
        }
        for(int i = 0; i < r; i++){
            // i , 0
            // i , c-1
            dfs(i,0,grid);
            dfs(i, c-1, grid);
        }
        
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