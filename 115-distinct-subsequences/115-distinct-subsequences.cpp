class Solution {
public:
    // Using Iteration
    int numDistinct(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int prime = 1e9+7;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<m+1;i++){
            dp[0][i]=0;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){

                if(s1[i-1]==s2[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }


        return dp[n][m];
    }
};



/*
Using Recurssion
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
*/