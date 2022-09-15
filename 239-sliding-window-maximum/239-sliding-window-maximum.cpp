class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<int> q;
        
        vector<int> ans;
        
        for(int i=0;i<k;i++){
            q.push(nums[i]);
            m[nums[i]]++;
        }
        
        ans.push_back(q.top());
        
        for(int i=k;i<nums.size();i++){
            m[nums[i-k]]--;
            // cout<<q.top()<<endl;
            q.push(nums[i]);
            m[nums[i]]++;
            while(m[q.top()] <= 0){
                q.pop();
            }
            ans.push_back(q.top());
        }
        
        return ans;
        
    }
};