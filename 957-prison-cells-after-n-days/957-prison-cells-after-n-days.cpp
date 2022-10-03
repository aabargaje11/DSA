class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> temp(8);
        vector<vector<int>> seen;
        
        while(n--){
            for(int i=1;i<7 ;i++){
                temp[i] = cells[i-1] == cells[i+1];
            }
            
            if (seen.size() && seen.front() == temp) return seen[n % seen.size()]; 
            else seen.push_back(temp);
            cells = temp;
        }
        return cells;
    }
};