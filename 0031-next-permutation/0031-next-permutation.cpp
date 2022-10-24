class Solution {
public:
    void reverse(int i, int l, vector<int>& nums ){
        while(i<l){
            int a = nums[i];
            nums[i] = nums[l];
            nums[l] = a;
            i++;
            l--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        
        int i = len - 2;
        
        
        while(i >= 0 and nums[i]>= nums[i+1]){
            i--;
        }
        if(i >= 0){
            int j = len - 1;
            while(nums[j] <= nums[i]) j--;
            swap(nums[i],nums[j]);
            
        }
        reverse(i+1,len-1, nums);
    }
};