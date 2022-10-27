class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<int> cost(n, INT_MAX);
        vector<int> time(n, INT_MAX);
        
        // cost , time, node
        using pi = pair<int, pair<int, int>>;
        vector<vector<pair<int, int>>> adj(n, vector<pair<int,int>>());
        priority_queue<pi, vector<pi>, greater<pi>>q;
        
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        cost[0] = passingFees[0];
        time[0] = 0;
        
        q.push({cost[0],{0,0}});
        // Similar to Dijiktras algorithm is used
        while(!q.empty()){
            pi top = q.top();
            q.pop();
            
            int cc = top.first;
            int tt = top.second.first;
            int nn = top.second.second;
            
            for(auto e:adj[nn]){
                if(tt + e.second > maxTime) continue;
                if((cost[e.first] > cc + passingFees[e.first]) ){
                    cost[e.first] = cc + passingFees[e.first];
                    time[e.first] = tt + e.second;
                    q.push({cost[e.first],{time[e.first], e.first}});
                }
                else if(time[e.first] > tt + e.second){
                    time[e.first] = tt + e.second;
                    q.push({cc + passingFees[e.first],{time[e.first], e.first}});
                }
            }
            
        }
        
        return cost[n-1]==INT_MAX ? -1 : cost[n-1];
        
        
    }
};