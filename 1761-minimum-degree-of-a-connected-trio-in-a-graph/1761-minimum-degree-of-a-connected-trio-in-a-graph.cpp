class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) 
    {   
        ios_base::sync_with_stdio(0); cin.tie(NULL);
        vector<vector<int>> adj(n+1, vector<int>(n+1));
        unordered_map<int, int> degree;
        
        for(vector<int>& edge : edges)
        {
            adj[edge[0]][edge[1]] =  1; adj[edge[1]][edge[0]] =  1;
            degree[edge[0]]++; degree[edge[1]]++;
        }
        int res = INT_MAX ;
        for(int i=1; i<=n; i++)
        {
            for(int j = i+1; j<=n; j++)
            {
                for(int k = j+1; k<=n; k++)
                {   
                    if(adj[i][j] && adj[j][k] && adj[k][i])
                    {
                        res = min(res, degree[i] + degree[j] + degree[k] - 6) ; 
                        //These three vertices would each share an edge with the 2 other vertices, that's 2 * 3 = 6 edges (degrees).
                        //But the degree of the trio does not count these edges inside, so we subtract 6 in this line.
                    }
                }
            }
        }

        if(res == INT_MAX){return -1;}
        else{return res;}
    }
};