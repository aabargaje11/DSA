class Solution {
public:
    int numSquares(int n) {
        vector<int> p(n+1,INT_MAX);
        if( n <=0 )return 0;
        
        p[0] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j = 1; j*j<= i;j++){
                p[i] = min(p[i], p[i - j*j]+1);
            }
        }
        return p[n];
    }
};