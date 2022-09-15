#define ll long long int
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<ll, vector<ll>, greater<ll>> q;
        q.push(1);
        
        
        for(int i = 0; i<n-1;i++){
            ll top = q.top();
            q.pop();
            
            while(q.size()> 0 and q.top() == top){
                q.pop();
            }
            
            q.push(2*top);
            q.push(3*top);
            q.push(5*top);
        }
        
        
        return q.top();
        
    }
};