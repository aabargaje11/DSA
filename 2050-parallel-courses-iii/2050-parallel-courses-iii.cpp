class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1,vector<int>()) ;
        vector<int> in(n+1,0);
        vector<int> start(n+1,0);
        for(auto r:relations){
            adj[r[0]].push_back(r[1]);
            // cout<<r[0]<<r[1]<<endl;
            in[r[1]]++;
        }
        
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        // vector<bool> visited(n+1, false);
        int ans = 0;
        cout<<"---------------------------------------"<<endl;
        while(!q.empty()){
            int len = q.size();
            
            while(len!=0 and !q.empty()){
                
                int front = q.front();
                // visited[front] = true;
                
                ans = max(ans, start[front] + time[front-1]);
                q.pop();
                cout<<front<<" "<<q.size()<<" "<<len<<endl;
                for(auto num:adj[front]){
                    start[num] = max(start[num], time[front-1] + start[front]);
                    in[num]--;
                    if(in[num] == 0){
                        q.push(num);
                        cout<<"Push "<<num<<endl;
                        
                    } 
                }
                
                
                len--;
            }
        }
        return ans;
    }
};