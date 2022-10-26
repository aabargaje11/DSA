class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1,vector<int>()) ;
        vector<int> in(n+1,0);
        vector<int> start(n+1,0);
        // Topological sort
        // MAke adjacency list and calculate indegree
        for(auto r:relations){
            adj[r[0]].push_back(r[1]);
            in[r[1]]++;
        }
        
        queue<int> q;
        // Push values with indegree zero to queue
        for(int i=1;i<=n;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        int ans = 0;
        while(!q.empty()){
            int len = q.size();
            
            while(len!=0 and !q.empty()){
                
                int front = q.front();
                
                ans = max(ans, start[front] + time[front-1]);
                q.pop();
                for(auto num:adj[front]){
                    // Update start time node destination node
                    start[num] = max(start[num], time[front-1] + start[front]);
                    // decrease indegree and append to queue if value becomes zero
                    in[num]--;
                    if(in[num] == 0){
                        q.push(num);                        
                    } 
                }
                
                
                len--;
            }
        }
        return ans;
    }
};