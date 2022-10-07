class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        //first value will be node second value will be distance
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>()) ;
        for(auto n:roads){
            adj[n[0]].push_back({n[1], n[2]});
            adj[n[1]].push_back({n[0], n[2]});
        }
        
        vector<int> path(n,0);
        vector<long long> distance(n, LONG_MAX);
        
        // first value will be distance second value will be node
        priority_queue<pair<long long , int>, vector<pair<long long , int>>, greater<pair<long long , int>>> q;
        
        
        q.push({0,0});
        distance[0] = 0;
        path[0] = 1;
        
        
        while(!q.empty()){
            long long distso = q.top().first;
            int val = q.top().second;
            q.pop();
            
            
            for(auto nn:adj[val]){
                int nnval = nn.first;
                int nndist = nn.second;
                
                // Push to q only if new value is less that existing
                if(distance[nnval] > distso + nndist){
                    distance[nnval] = (distance[val] + nndist);
                    q.push({distance[nnval],nnval});
                    path[nnval] = path[val]%mod;
                }
                else if(distance[nnval] == distso + nndist){
                    path[nnval] = (path[nnval] + path[val])%mod;
           
                }
            }
        }
        
        return path[n-1];
        
    }
};