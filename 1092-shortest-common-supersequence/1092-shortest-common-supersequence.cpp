class Solution {
public:
    string shortestCommonSupersequence(string t1, string t2) {
        vector<vector<int>> dp(t1.size()+1,vector<int>(t2.size()+1,0));
        
        // Create DP similar to Longest common subsequence
        for(int i=1;i<=t1.size();i++){
            for(int j=1;j<=t2.size();j++){
                // Current char is matching. Increase count by 1
                if(t1[i-1] == t2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            
                // Character not match
                // Try to move one character ahead for string one by one.
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
          
        }
        
        
        int i = t1.size(), j=t2.size();
        string ans = "";
        
        // Create supersequence using DP array.
        while(i > 0 && j > 0){
            if(t1[i-1] == t2[j-1]){
                ans+= t1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans+= t1[i-1];
                i--;
                
            }
            else{
                ans += t2[j-1];
                j--;
                
            }
        }
        
        
        while(i>0){
            ans+= t1[i-1];
            i--;
        }
        
        while(j>0){
            ans += t2[j-1];
            j--;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};