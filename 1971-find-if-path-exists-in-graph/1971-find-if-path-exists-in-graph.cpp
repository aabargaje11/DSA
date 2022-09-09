class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n,false);
        
        // Create adjancency matrix from gievn edges array
        // Note : Grpaph is bidirectional.
        // i.e Edge is present between u -> v and v -> u
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        q.push(source);
        visited[source] = true;
        
        // Visit all nodes that are connected to source.
        // And store visited status for each and every node.
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(auto num:adj[top]){
                if(num == destination) return true;
                if(!visited[num]){
                    q.push(num);
                    visited[num] = 1;
                }
            }
        }

        return false;
        
    }
};