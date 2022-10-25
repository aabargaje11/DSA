class Solution {
public:
    int mod = 1e9 + 7;
    int dfs(int node, vector<int> &dist, vector<vector<pair<int, int>>> &graph, vector<int> &dp) {
        if(node == dp.size()-1) return 1;
        if(dp[node] != -1) return dp[node];
        int ans = 0;
        for(auto nbr : graph[node]) {
            if(dist[node] > dist[nbr.first]) {
                ans = (ans + dfs(nbr.first, dist, graph, dp))%mod;
            }
        }
        return dp[node] = ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, n});
        dist[n] = 0;
        // CAlculate shortest distance using dijiktra algorithm
        while(!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            if(dist[p.second] != p.first) 
                continue;
            for(auto nbr : graph[p.second]) {
                if(dist[nbr.first] > p.first+nbr.second) {
                    dist[nbr.first] = p.first+nbr.second;
                    pq.push({dist[nbr.first], nbr.first});
                }
            }
        }
        vector<int> dp(n+1, -1);
        // DFS call to get count of numbers
        return dfs(1, dist, graph, dp);
    }
};