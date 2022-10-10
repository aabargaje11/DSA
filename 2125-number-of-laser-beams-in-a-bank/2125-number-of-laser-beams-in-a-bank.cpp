class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int pre = 0, l = 0;
        int i=0;
        int ans = 0;
        while(pre == 0 and i<bank.size()){
            for(auto c:bank[i]){
                if(c == '1'){
                    pre++;
                }
            }
            i++;
        }
        
        for(int j=i;j<bank.size();j++){
            l = 0;
            for(auto c:bank[j]){
                if(c == '1'){
                    l++;
                }
            }
            
            ans = ans + pre * l;
            if(l!=0)
                pre = l;
        }
        return ans;
    }
};