class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<int>> r(n,vector<int>()), b(n, vector<int>());
        vector<bool> rv(n, false),bv(n,false);
        vector<int> ans(n,-1);

        // Adjacency list for each colour
        for(auto rr:redEdges){
            r[rr[0]].push_back(rr[1]);
        }
        for(auto gg:blueEdges){
            b[gg[0]].push_back(gg[1]);
        }        
        
        // track number of edge colour
        queue<pair<int, char>> q;
        q.push({0,'n'});
        // Update ans while pushing to q
        ans[0] = 0;
        int level = 0;
        bv[0] = true;
        rv[0] = true;
              
              
        while(!q.empty()){
            int len = q.size();
            level++;
            while(len){
                pair<int, char> topp = q.front();
                q.pop();
                int val = topp.first;
                char col = topp.second;
                
                if(col != 'r'){
                    // Iterate all red
                    for(auto num:r[val]){
                        if(!rv[num]){
                            q.push({num,'r'});
                            if(ans[num] == -1)ans[num] = level;
                            rv[num] = true;
                        }
                    }
                }
                if(col != 'b'){
                    // Iterate all blue
                    for(auto num:b[val]){
                        if(!bv[num]){
                            q.push({num,'b'});
                            if(ans[num] == -1)ans[num] = level;
                            bv[num] = true;
                        }
                    }
                }
          
                
                len--;
            }     
        }
              
        return ans;
              
    }
};