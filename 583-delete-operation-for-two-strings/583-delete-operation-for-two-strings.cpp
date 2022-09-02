class Solution {
public:
    int minDistance(string w1, string w2) {
        // We have to find minimum number of steps required to make 
        // word1 and word2 the same
        // i.e This can be solved by finding longest common subsequence
        // If can get length of longest common subsequence then remaning 
        // elements have to be removed.
        int l1 = w1.size();
        int l2 = w2.size();
        
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        
        // Finding longest common subsequence
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(w1[i-1] == w2[j-1]) dp[i][j]= 1+ dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // dp[l1][l2] store length of longest common subsequence
        return l1  +l2 - 2*dp[l1][l2];
    }
};