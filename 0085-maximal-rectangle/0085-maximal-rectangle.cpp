class Solution {
public:
    void solve(vector<int>& heights, int &ans) {
        int l=heights.size();
        vector<int> leftSmall(l,0), rightSmall(l,0);
        
        stack<int> s;
        
        for(int i=0;i<l;i++){
            while(!s.empty() and heights[s.top()] >= heights[i] ){
                s.pop();
            }
            
            leftSmall[i] = (s.empty())? 0:s.top()+1;
            //cout<<leftSmall[i];
            s.push(i);
        }
        //cout<<endl;
        while(!s.empty()) s.pop();
        
        for(int i=l-1;i>=0;i--){
            while(!s.empty() and heights[s.top()] >= heights[i] ){
                s.pop();
            }
            
            rightSmall[i] = (s.empty())? l-1:s.top()-1;
            //cout<<rightSmall[i];
            s.push(i);
        }
        //cout<<endl;
        
        for( int i=0;i<l;i++){
            ans = max(ans, (rightSmall[i] - leftSmall[i] + 1)*heights[i]);
            //cout<<rightSmall[i]<< leftSmall[i] <<heights[i]<<endl;
        }

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(), 0);
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = 0;
        
        for(int i=0;i<r;i++){
            
            for(int j=0;j<c;j++){
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            
            solve(heights,ans);
        }
        
        return ans;
    }
};