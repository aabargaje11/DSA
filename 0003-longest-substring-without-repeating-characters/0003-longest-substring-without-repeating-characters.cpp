class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int  j = 0;
        unordered_map<char,int> count;
        int ans = 0;
        for(int i=0;i<n;i++){
            int c = s[i];
            // cout<<index<<endl;
            while(count[c]!=0){
                count[s[j]]--;
                j++;
            }
            count[c]++;
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};