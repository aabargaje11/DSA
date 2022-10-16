class Solution {
public:
    bool isLoop(int i,vector<vector<int>> &adj, vector<int> &visited, vector<int> &tv){
        if(tv[i]) return true;
        if(visited[i]) return false;
        
        
        visited[i] = true;
        tv[i] = true;
        
        for(auto nn:adj[i]){
            if(isLoop(nn,adj,visited,tv)) return true;
        }
        
        
        tv[i] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> visited(n, 0), tv(n,0);
        vector<vector<int>> adj(n, vector<int>());
        
        
        for(auto n:prerequisites){
            adj[n[0]].push_back(n[1]);
        }
        
        
        for(int i=0;i<n;i++){
            if(isLoop(i, adj, visited, tv)) return false;
        }
        
        return true;
    }
};