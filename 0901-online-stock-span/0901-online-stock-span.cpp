class StockSpanner {
public:
    stack<pair<int, int>> s;
    StockSpanner() {
        
    }
    
    // Use monotonic stack
    // We want to find minimum values are left side. i.e Bigger value are right side.
    // FInd stack o=with decreasing elements
    int next(int price) {
        
        int ans = 1;
        while(!s.empty() and s.top().first <= price){
            
            ans = ans + s.top().second;
            s.pop();
        }
        s.push({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */