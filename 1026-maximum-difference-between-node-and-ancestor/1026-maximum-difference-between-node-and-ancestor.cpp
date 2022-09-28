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
    void solve(TreeNode* root, int mx, int mn, int &ans){
        if(!root) return;
        ans = max(abs(mx - root->val), ans);
        ans = max(abs(mn- root->val), ans);
        
        mn = min(root->val, mn);
        mx = max(root->val, mx);
        
        solve(root->left, mx, mn, ans);
        solve(root->right, mx, mn, ans);
        

    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        int mx = root->val, mn = root->val;
        solve(root, mx, mn, ans);
        
        return ans;
    }
};