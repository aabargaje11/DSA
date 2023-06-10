//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int i, vector<int> adj[], vector<bool> v, int p){
        if(v[i]) return true;
        v[i] = true;
        
        for(auto vv:adj[i]){
            if(p != vv and dfs(vv, adj, v, i)){
                return true;
            }
        }
        
        
        return false;
    }
  
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int l = V;
        vector<bool> v(l, false);

        for(int i=0;i<l;i++){
            if(!v[i] and dfs(i, adj, v, -1)){
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends