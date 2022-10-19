class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count;
        // All process with zero wait time are stores in q
        priority_queue<int> q;
        
        // count , wait timer
        // Process with wait time are stored here
        queue<pair<int,int>> wait;

        
        for(auto c:tasks){
            count[c]++;
        }
        
        for(auto cc:count){
            q.push(cc.second);
        }
        
        int ans = 0;
        
        while(!wait.empty() or !q.empty()){
            ans++;
            
            if(!q.empty()){
                int top = q.top();
                q.pop();
                top--;
                // Push current processed task to waiting queue
                if(top!=0){
                    wait.push({top, ans + n});
                }
            }
            
            // If wait time is over then push this process back to main queue
            if(!wait.empty() and wait.front().second == ans){
                q.push(wait.front().first);
                wait.pop();
            }
            
        }
        
        
        
        return ans;
        
    }
};