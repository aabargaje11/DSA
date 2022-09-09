class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        set<int> s;
        vector<vector<int>> adj(n+1,vector<int>());
        
        for(int i=1;i<=n;i++){
            s.insert(i);
        }
        
        
        for(auto x:trust){
            adj[x[1]].push_back(x[0]);
            if(s.find(x[0])!=s.end())
                s.erase(x[0]);
        }
        
        
        if(s.size()!=1) return -1;
        
        int j = *s.begin();
        
        if(adj[j].size() == n-1) return j;
        return -1;
        
    }
};