class Solution {
public:
    int solve(string &w1, string &w2, int i, int j){
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        
        if(w1[i] == w2[j])
            return solve(w1,w2,i-1,j-1);
        
        int kk = INT_MAX;
        kk = min(kk, solve(w1,w2,i-1,j));
        kk = min(kk, solve(w1,w2,i,j-1));
        kk = min(kk, solve(w1,w2,i-1,j-1));
        return kk + 1;
    }
    int minDistance(string w1, string w2) {
        int l1 = w1.size(), l2 = w2.size();
        
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        
        for(int i=1;i<=l1;i++) dp[i][0] = i;
        for(int i=1;i<=l2;i++) dp[0][i] = i;
        
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(w1[i-1] == w2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    int kk = INT_MAX;
                    kk = min(kk,dp[i-1][j-1]);
                    kk = min(kk,dp[i-1][j]);
                    kk = min(kk,dp[i][j-1]);
                    dp[i][j] = kk + 1;
                    
                }
            }
        }
        
        return dp[l1][l2];

        
    }
};