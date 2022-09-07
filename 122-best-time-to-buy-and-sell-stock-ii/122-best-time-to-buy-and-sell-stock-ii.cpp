class Solution {
public:
    int f(int ind, int buy, vector<int>& p, int n,vector<vector<int>> &dp)
    {
        if(ind == n) return 0;
        
        int profit = 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            profit = max(-1 * p[ind]+ f(ind+1, 0, p, n,dp), f(ind+1,1,p,n,dp));
        }
        else{
            profit = max( p[ind]+ f(ind+1, 1, p, n,dp), f(ind+1,0,p,n,dp));
        }
        
        return dp[ind][buy] = profit;

    }
    
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int val = 0;
        vector<vector<int>> dp(len, vector<int>(2,-1));
        return f(0, 1, prices, len,dp);
    }
};