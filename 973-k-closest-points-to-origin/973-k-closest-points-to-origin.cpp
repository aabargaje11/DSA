class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>, vector<pair<double,vector<int>>>, greater<pair<double,vector<int>>> > q;
        vector<vector<int>> ans;
        
        for(auto x:points){
            double sq = sqrt(x[0]*x[0] + x[1]*x[1]);
            q.push({sq,{x[0],x[1]}});
            cout<<sq<<" ";
        }
        cout<<endl;
        
        
        for(int i=0;i<k;i++){
            ans.push_back(q.top().second);
            cout<<q.top().first<<" ";
            q.pop();
        }
        cout<<endl;
        return ans;
        
    }
};