class Solution {
public:
    void solve(vector<int> heights, int &ans){
        int n = heights.size();
        vector<int> left(n,0),right(n,n-1);
        // Similar to https://leetcode.com/problems/largest-rectangle-in-histogram/
        // Largest rectangle in histogram.
        // Find Largest rectangle in histogram for each row.
        stack<int>s;
        
        for(int i=0;i<n;i++){
            
            while(!s.empty() and heights[s.top()] >= heights[i]){
                s.pop();
            }
            
            left[i] = (s.empty())? 0:s.top() + 1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and heights[s.top()] >= heights[i]){
                s.pop();
            }
            right[i] = (s.empty())? n-1:s.top() - 1;
            s.push(i);
        }
        int temp = 0;
        
        for(int i=0;i<n;i++){
            int l=left[i], r = right[i];
            
            temp = (r-l+1)*(heights[i]);
            ans = max(ans,temp);
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