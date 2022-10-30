class Solution {
public:
    int longestValidParentheses(string st) {
        int ans = 0;
        stack<int> s;
        s.push(-1);
        
        // Info from https://www.youtube.com/watch?v=VdQuwtEd10M&t=11s
        for(int i=0;i<st.size();i++){
            if(st[i] == '('){
                s.push(i);
            }
            else{
                s.pop();
                if(s.empty()){
                    s.push(i);
                }
                else{
                    int len = i - s.top();
                    ans = max(ans,len);
                }
            }
        }
        
        return ans;
    }
};