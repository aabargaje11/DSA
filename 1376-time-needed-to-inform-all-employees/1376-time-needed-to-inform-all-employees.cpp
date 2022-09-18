class Solution {
public:

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        
        vector<vector<int>> adj(n,vector<int>());
        
        for(int i=0;i<n;i++){
            if(manager[i] != -1)
            adj[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        q.push({headID,0});
        
        while(!q.empty()){
            int len = q.size();
            // cout<<"Len: "<<len<<endl;
            
            
            int minn = INT_MIN;
            while(len!=0){
                int temp = q.front().first;
                int val = q.front().second;
                ans = max(val,ans);
                // cout<<temp<<endl;
                // minn = max(minn,informTime[temp]);
                q.pop();
                
                for(auto x:adj[temp]){
                    q.push({x,val+informTime[temp]});
                }
                
                len--;
            }
            // cout<<"----------"<<endl;
        }
        
        return ans;
    }
};