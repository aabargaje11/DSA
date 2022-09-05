class Solution {
public:
    bool f(int i, int j, string &s, string &p,vector<vector<int>> &dp){
        if(i == -1 && j == -1) return true;
        if(i != -1 && j == -1) return false;
        
        
        if(i == -1 && j != -1){
            for(int ii = 0; ii <= j;ii++){
                if( p[ii] != '*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        
        if( p[j] == '*')
            return dp[i][j] =  f(i-1,j,s,p,dp) ||  f(i,j-1,s,p,dp);
        
        if( p[j] == '?')
            return dp[i][j] = f(i-1,j-1,s,p,dp);
        
        if( p[j] == s[i])
            return dp[i][j] = f(i-1,j-1,s,p,dp);
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int l = s.size(), m = p.size();
        
        vector<vector<int>> dp(l, vector<int>(m,-1));
        
        return f(l-1, m-1,s , p,dp);
        
    }
};