class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0, curr = 0;
        
        int r = grid.size(), c = grid[0].size();

        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        
        queue<pair<int,int>> q;
        
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    curr = 0;
                    
                    q.push({i,j});
                    grid[i][j] = 0;
                    
                    while(!q.empty()){
                        int rr = q.front().first, cc = q.front().second;
                        q.pop();
                        curr++;
                        
                        for(auto x:dir){
                            int nr = rr + x[0], nc = cc + x[1];
                            
                            if(nr >=0 and nc >= 0 and nr < r and nc < c and grid[nr][nc] == 1){
                                q.push({nr,nc});
                                grid[nr][nc] = 0;
                            }
                        }
                        
                    }
                }
                
                ans = max(ans, curr);
            }
        }
        
        return ans;
        
    }
};