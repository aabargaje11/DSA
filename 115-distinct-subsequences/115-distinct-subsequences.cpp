class Solution {
public:
    int solve(string &s, string &t, int n, int m,vector<vector<int>> &dp){
        if(m == -1 ) return 1;
        if(n == -1 ) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        
        int val = 0;
        if(s[n] == t[m]) 
            val = solve(s,t, n-1, m-1,dp);
        
        val += solve(s,t,n-1,m,dp);
        
        return dp[n][m] = val;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        solve(s,t,n-1,m-1,dp);

        return dp[n-1][m-1];
        
    }
};