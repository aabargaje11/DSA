class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n,false);
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        q.push(source);
        visited[source] = true;
        
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(auto num:adj[top]){
                if(!visited[num]){
                    q.push(num);
                    visited[num] = 1;
                }
            }
        }

        return visited[destination];
        
    }
};