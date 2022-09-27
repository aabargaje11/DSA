class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int temp = label, count = 1;
        vector<int> ans ;
        ans.push_back(label);
        
        // Calaculate height of tree
        while(temp!=1){
            temp/=2;
            count++;
        }
        temp = label;
        
        
        while(count!=1){
            count--;

                int start = pow(2, count-1) ;  // Find starting element of previous level
                int end = pow(2, count) - 1;   // Find ending element of previous level
                int val = temp / 2;            //  Finf=d half
                int diff = val - start;             
                temp = end - diff;
                ans.insert(ans.begin(),temp);
        }
        

        return ans;
    }
};