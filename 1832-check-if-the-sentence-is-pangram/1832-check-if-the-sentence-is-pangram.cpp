class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> visited(26,1);
        int count = 26;
        for(auto c:sentence){
            if(visited[c-'a'] == 1){
                count -= 1;
                visited[c-'a'] = 0;
            }    
        }
        
        return count == 0;
    }
};