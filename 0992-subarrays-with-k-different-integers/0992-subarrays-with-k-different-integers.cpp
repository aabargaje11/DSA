class Solution {
public:
    int solve(vector<int>&nums, int k){
        unordered_map<int,int> m;
        int n = nums.size();
        
        int j = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            int nn = nums[i];
            if(!m[nn]++) k--;
            while(k < 0){
                m[nums[j]]--;
                if(!m[nums[j]])k++;
                j++;
            }
            
            ans += i - j + 1;
            
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};