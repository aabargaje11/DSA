class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int len = p.size();
        vector<vector<int>> after(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        
        for(int ind = len-1; ind>=0; ind--){
            for(int buy = 0 ; buy < 2 ; buy++){
                for(int b = 1 ; b <= k; b++){
                    int val = INT_MIN;
                    if(buy == 1){
                        val = max(-1 * p[ind] + after[0][b], after[1][b]);
                    }
                    else{
                        val = max(p[ind] + after[1][b-1],after[0][b]);
                    }
                    
                    curr[buy][b] = val;
                }
                
            }
            after = curr;
        }
        
        return after[1][k];     
    }
};