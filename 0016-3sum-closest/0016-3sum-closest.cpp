class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int closest = nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for(int i=0;i<len;i++){
            int j=i+1, k=len-1;
            
            while(j<k){
                int summ = nums[i]+nums[j]+nums[k];
                closest = (abs(closest-target)<abs(summ-target))?closest:summ;
                if(summ == target){
                    return target;
                }
                if(summ > target){
                    k--;
                }
                else{
                    j++;
                }
                
            }
            
        }
        
        
        return closest;
        
    }
};
