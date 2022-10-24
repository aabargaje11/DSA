class Solution {
public:

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses,vector<int>());
        vector<vector<bool>> r(numCourses, vector<bool>(numCourses,false));
        
        
        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        
        
        for(int i=0;i<numCourses;i++){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int top = q.front();
                q.pop();
                
                for(auto nnn:adj[top]){
                    if(!r[i][nnn]){
                        r[i][nnn] = true;
                        q.push(nnn);
                    }
                }
            }
        }
        
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            ans[i] = r[queries[i][1]][queries[i][0]];
        }
        return ans;
    }
};