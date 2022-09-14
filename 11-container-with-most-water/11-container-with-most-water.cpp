class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int s = 0, e = height.size()-1;
        
        while(s < e)
        {
                int in = min(height[s], height[e]);
            // cout<<in<<endl;
            ans = max(ans, in * (e-s));
            if(height[s] < height[e])
                s++;
            else
                e--;
        }    
        
        return ans;
    }
};