class Solution {
public:
    bool dfs(string str, unordered_map<string, vector<string>>  &adj, unordered_map<string, int> &pre, unordered_map<string, bool> &v){
        if(pre[str] != -1) return pre[str];
        if(v[str]) return pre[str] = 0;
        v[str] = true;
        
        if(adj[str].size()==0)return pre[str] = 0;
        for(auto ad:adj[str]){
            if(!dfs(ad,adj,pre,v)) return pre[str] = 0;
        }
        v[str] = false;
        return pre[str] = 1;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>>  adj;
        unordered_map<string, int> pre;
        
        for(int i=0;i<recipes.size();i++){
            pre[recipes[i]] = -1;
            for(auto ii:ingredients[i]){
                adj[recipes[i]].push_back(ii);
                pre[ii] = -1;
            }
        }
        
        vector<string> ans;
        
        for(auto str:supplies ){
            pre[str] = 1;
        }
        
        unordered_map<string, bool> v;
        for(auto str:recipes){
            unordered_map<string, bool> v;
            if(dfs(str,adj,pre,v)){
                ans.push_back(str);
            }
        }
        return ans;
    }
};