class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph,vector<bool> &visited, vector<bool> &cv,vector<bool> &pc){
        if(cv[i]){
            return pc[i] = true;
        }
        if(visited[i]) return false;
        visited[i] = true;
        cv[i] = true;
        
        
        for(auto x:graph[i])
        {
            if(dfs(x,graph,visited,cv,pc)) return pc[i] = true;
        }
        
        cv[i] = false;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false), cv(n,false), pc(n,false);
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            dfs(i,graph,visited,cv,pc);
        }
        
        
        for(int i=0;i<n;i++){
            if(!pc[i]) ans.push_back(i);
        }
        
        return ans;

        
        
    }
};