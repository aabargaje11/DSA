class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        vector<vector<char>> chars {
            {'a','b','c'},
            {'d','e','f'},
            {'g','h','i'},
            {'j','k','l'},
            {'m','n','o'},
            {'p','q','r','s'},
            {'t','u','v'},
            {'w','x','y','z'}
        };
        if(digits.size()==0){
            return ans;
        }
        ans.push_back("");
        
        for(int i=0;i<digits.size();i++){
            
            // Get all chars for given number
            int num = digits[i]-'0';
            string pre_string;
            int vect_len = ans.size();
            
            while(vect_len!=0){
                pre_string = ans[0];
                ans.erase(ans.begin());
                
                for(int j=0;j<chars[num-2].size();j++){
                    ans.push_back(pre_string+chars[num-2][j]);
                }
                vect_len--;
            }
            
        }
        return ans;
        
    }
};