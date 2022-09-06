class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> h(len,-1);
        
        for(int i=len-2;i>=0;i--){
            h[i] = max(prices[i+1],h[i+1]);
        }
        
        int ans = 0;
        for(int i=0;i<len-1;i++){
            int temp = h[i] - prices[i];
            ans = max(temp,ans);
        }
        
        return ans;
    }
};