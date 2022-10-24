class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<int> ans;
		if(n == 1) {ans.push_back(0); return ans;}
		vector<int> adj[n];
		vector<int> indegree(n,0);
		for(int i = 0 ; i < edges.size() ;  i++){
			adj[edges[i][0]].push_back(edges[i][1]);
			adj[edges[i][1]].push_back(edges[i][0]);
			indegree[edges[i][0]]++;
			indegree[edges[i][1]]++;
		}

		queue<int> q;
		for(int i = 0 ; i < indegree.size() ; i++) if(indegree[i] == 1) q.push(i);
		while(!q.empty()){
			ans.clear();
			int s = q.size();
			for(int i = 0 ; i < s ; i++){
				int curr = q.front() ; q.pop();
				ans.push_back(curr);
				for(auto it : adj[curr]){
					indegree[it]--;
					if(indegree[it] == 1) q.push(it);
				}
			}
		}
		return ans;
	}
};