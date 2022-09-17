class Solution {
public:
    void dfs(int curr, vector<bool> &visited, int &count, vector<vector<int>>& rooms){
        if(visited[curr]) return;
        visited[curr] = true;
        count++;
        
        for(auto num:rooms[curr]){
            dfs(num, visited, count, rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len = rooms.size();
        vector<bool> visited(len,false);
        int count = 0;
        
        dfs(0, visited, count, rooms);
        
        if(count == len) return true;
        return false;
        
    }
};