/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        
        // Initially answer will be 1
        int ans = 1, sum = root->val;
        
        
        queue<TreeNode*> s;
        s.push(root);
    
        int count = 0;
        // BFS iteration
        while(!s.empty()){
            int len = s.size();
            int temp = 0;
            count += 1;
            while(len!=0){
                temp+= s.front()->val;
                if(s.front()->left) s.push(s.front()->left);
                if(s.front()->right) s.push(s.front()->right);
                s.pop();
                
                len--;
            }
            
            // If sum of cureent level is greater than previous update answer.
            if(temp > sum){
                sum = temp;
                ans = count;
            }
        }
        return ans;
    }
};