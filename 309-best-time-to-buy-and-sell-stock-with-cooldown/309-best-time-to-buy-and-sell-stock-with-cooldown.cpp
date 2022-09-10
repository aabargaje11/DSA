class Solution {
public:
    int solve(vector<int>& p, int curr, int buy,vector<vector<int>> &dp, int num){
        if(curr >= p.size()){
            return 0;
        }
        int val;
        if(dp[curr][buy] != -1) return dp[curr][buy];
        if(buy){
            val = max(-1*p[curr] + solve(p,curr+1,0,dp,num+1), solve(p, curr+1,1,dp,num));            
        }
        else{
            val = max(p[curr]+ solve(p,curr+2,1,dp,num), solve(p,curr+1,0,dp,num));
        }
        dp[curr][buy] = val;
        return val;
        
    }
    
    int maxProfit(vector<int>& p) {
        int len = p.size();
        vector<vector<int>> dp(len, vector<int>(2,-1));
        
        return solve(p,0,1,dp,0);
        
    }
};