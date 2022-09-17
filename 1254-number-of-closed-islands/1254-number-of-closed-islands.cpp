class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>& grid){
        int r = grid.size(), c = grid[0].size();
        
        if( i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == 1) return;
        grid[i][j] = 1;
        dfs(i+1,j,grid) ; 
        dfs(i-1,j,grid) ;
        dfs(i,j+1,grid) ;
        dfs(i,j-1,grid);

        
    }

    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();

        int ans = 0;
        
        
        for(int i=0;i<r;i++){
            dfs(i,0, grid);
            dfs(i,c-1, grid);
        }
        for(int i=0;i<c;i++){
            dfs(0,i, grid);
            dfs(r-1,i, grid);
        }        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs(i,j,grid);
                    
                }
            }
        }

        return ans;
    }
};