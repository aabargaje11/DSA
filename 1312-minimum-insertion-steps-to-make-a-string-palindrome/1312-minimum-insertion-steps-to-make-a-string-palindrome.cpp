class Solution {
public:
    int minInsertions(string s) {
        string t1 = s, t2 = s;
        reverse(t2.begin(),t2.end());
        vector<vector<int>> dp(t1.size()+1,vector<int>(t2.size()+1,0));
        
        for(int i=1;i<=t1.size();i++){
            for(int j=1;j<=t2.size();j++){
                if(t1[i-1] == t2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
          
        }
        
        return t1.size() - dp[t1.size()][t2.size()];        
    }
};