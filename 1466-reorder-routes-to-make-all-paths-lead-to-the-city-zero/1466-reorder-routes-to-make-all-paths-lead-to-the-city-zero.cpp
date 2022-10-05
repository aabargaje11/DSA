class Solution {
public:
    void solve(int start, int &ans, vector<bool> &visited, vector<vector<int>> &adj){
        visited[start] = true;

        for(int i=0;i<adj[start].size();i++){
            int a = adj[start][i];
            if(!visited[abs(a)]){
                if(a > 0) ans++;
                solve(abs(a), ans, visited, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n , vector<int>());
        vector<bool> visited(n,false);
        for(auto e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(-e[0]);
        }

        int ans = 0;

        solve(0, ans, visited, adj);

        return ans;

    }
};