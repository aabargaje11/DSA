// Using Iteration
class Solution {
public:

    int maxProfit(vector<int>& p) {
        int len = p.size();
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        
        for(int ind = len-1; ind>=0; ind--){
            for(int buy = 0 ; buy < 2 ; buy++){
                for(int b = 1 ; b <= 2; b++){
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
        
        return after[1][2];
    }
};

// Using recurssion
/*
class Solution {
public:
    int solve(int ind, int buy, vector<int>& p, int n, int b,vector<vector<vector<int>>> &dp){
        if(ind == n or b==0) return 0;
        int val = INT_MIN;
        
        if(dp[ind][buy][b] != -1) return dp[ind][buy][b];
        if(buy){
            val = max(-1 * p[ind] + solve(ind+1,0,p,n,b,dp), solve(ind+1,1,p,n,b,dp));
        }
        else{
            val = max(p[ind] + solve(ind+1,1,p,n,b-1,dp),solve(ind+1,0,p,n,b,dp));
        }
        
        return dp[ind][buy][b] = val;
    }
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(2,vector<int>(3,-1)));
        
        return solve(0, 1, prices, len,2,dp);
    }
};

*/