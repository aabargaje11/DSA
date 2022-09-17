class Solution {
public:
    void DFS(vector<vector<char>>& board, int i, int j){
        int r = board.size(), c = board[0].size();
        
        if(i == r || i<0 || j==c || j<0 || board[i][j] != 'O') return;
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        board[i][j] = 'B';
        
        for(auto x:dir){
            DFS(board,x[0]+i,x[1]+j);
        }
        return ;
        
    }
    
    void solve(vector<vector<char>>& board) {
        int r = board.size(), c = board[0].size();
        vector<vector<int>> visited(r,vector<int>(c,0));
    
        for(int i=0;i<r;i++){
            if(board[i][0] == 'O')
                DFS(board,i,0);
        }
        for(int i=0;i<r;i++){
            if(board[i][c-1] == 'O')
                DFS(board,i,c-1);
        }
        for(int i=0;i<c;i++){
            if(board[0][i] == 'O')
                DFS(board,0,i);
        }
        for(int i=0;i<c;i++){
            if(board[r-1][i] == 'O')
                DFS(board,r-1,i);
        } 
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j] == 'O') {
                   board[i][j] = 'X'; 
                } 
                if(board[i][j] == 'B'){
                     board[i][j] = 'O';
                }
            }
        }
        
        
        
    }
};