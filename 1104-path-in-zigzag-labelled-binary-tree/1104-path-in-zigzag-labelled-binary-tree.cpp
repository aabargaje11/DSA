class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int temp = label, count = 1;
        vector<int> ans ;
        ans.push_back(label);
        
        
        while(temp!=1){
            temp/=2;
            count++;
        }
        temp = label;
        
        
        while(count!=1){
            count--;
            
            // Odd
            // if(count%2==1){
                int start = pow(2, count-1) ;
                int end = pow(2, count) - 1;
                int val = temp / 2;
                int diff = val - start;
                temp = end - diff;
                ans.insert(ans.begin(),temp);
            // }else{
            //     temp = temp / 2;
            //     ans.insert(ans.begin(),temp);
            // }
        }
        

        return ans;
    }
};