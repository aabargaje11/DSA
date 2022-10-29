class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        int del = n - k;
        vector<int> s;
        
        for(int i=0;i<n;i++){
            while(!s.empty() and s.back() > nums[i] and del){
                s.pop_back();
                del--;
            }
            s.push_back(nums[i]);
        }
        
        vector<int> ans(s.begin(), s.begin()+k);
        return ans;
    }
};