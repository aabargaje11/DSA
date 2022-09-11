class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        
        int n = nums.size();
        vector<int> curr(n+1,0), next(n+1,0);
        for(int i = n-1;i>=0;i--){
            for(int p = i-1;p>=-1;p--){
                int take = 0;
                if( p == -1 or nums[i] > nums[p]){
                    take = next[i+1]+1;

                }

                int nottake = next[p+1]; 
                
                curr[p+1] = max(take,nottake);
            }
            next = curr;
        }
        
        
        return curr[0];
        
    }
};