class Solution {
public:
    bool loopPresent(int curr,vector<bool> &visited, vector<bool> &dfs, vector<vector<int>> &adj,
                    vector<int> &ans){
        if(dfs[curr]) return true;
        if(visited[curr]) return false;
        
        visited[curr] = true;
        dfs[curr] = true;
        
        for(auto x:adj[curr]){
            if(loopPresent(x,visited,dfs, adj,ans)) return true; 
        }
        
        
        dfs[curr] = false;
        ans.push_back(curr);
        
        return false;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false), dfs(numCourses, false);
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> ans;
        
        
        for(auto x:prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        
        
        
        for(int i=0;i<numCourses;i++){
            // Loop present mean we can not complete courses. Hence return false
            if(loopPresent(i,visited,dfs, adj, ans)) return {};    
        }
        
        
        return ans;        
    }
};

