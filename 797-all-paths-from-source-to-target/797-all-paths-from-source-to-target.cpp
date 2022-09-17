class Solution {
public:
    void solve(int s, int len,vector<vector<int>>& adj, vector<int> temp,vector<vector<int>> &ans ){
        temp.push_back(s);
        if(s == len-1){
            ans.push_back(temp);
            return;
        }
        
        
        for(auto num:adj[s]){
            solve(num,len,adj,temp,ans);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        
        vector<vector<int>> ans;
        int len = adj.size();

        vector<int> temp ;
        solve(0, len, adj, temp, ans);
        
        return ans;
        
    }
};