class Solution {
public:

    int longestCommonSubsequence(string t1, string t2) {
        vector<vector<int>> dp(t1.size()+1,vector<int>(t2.size()+1,0));
        
        for(int i=1;i<=t1.size();i++){
            for(int j=1;j<=t2.size();j++){
                // Current char is matching. Increase count by 1
                if(t1[i-1] == t2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                
                // Character not match
                // Try to move one character ahead for string one by one.
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
          
        }
        
        return dp[t1.size()][t2.size()];
    }
};