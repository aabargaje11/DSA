//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int i, vector<int> &t, vector<int> &v, vector<int> adj[]){
        if(t[i]) return true;
        if(v[i]) return false;
        t[i] = true;
        v[i] = true;
        
        for(auto ii:adj[i]){
            if(dfs(ii,t,v,adj)) return true;
        }
        
        t[i] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> t(V, false), v(V, false);
        
        
        for(int i=0;i<V;i++){
            if(!v[i]){
                if(dfs(i,t,v,adj)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends