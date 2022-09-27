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
    void solve(TreeNode* root, vector<int>& to_delete, vector<TreeNode*> &ans){
        if(!root) return;
        if(root->left){
            solve(root->left, to_delete, ans);
            if(find(to_delete.begin(), to_delete.end(), root->left->val) != to_delete.end()){
                TreeNode* temp = root->left;
                root->left = NULL;
                if(temp->left)
                    ans.push_back(temp->left);
                if(temp->right)
                    ans.push_back(temp->right);
            }
        }
            
        
        if(root->right){
            solve(root->right, to_delete, ans);
            if(find(to_delete.begin(), to_delete.end(), root->right->val) != to_delete.end()){
                TreeNode* temp = root->right;
                root->right = NULL;
                if(temp->left)
                    ans.push_back(temp->left);
                if(temp->right)
                    ans.push_back(temp->right);
            }
        }
            
        
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        solve(root, to_delete, ans);
        if(find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()){
            TreeNode* temp = root;
            if(temp->left)
                ans.push_back(temp->left);
            if(temp->right)
                ans.push_back(temp->right);
        }
        else{
            ans.push_back(root);
        }
        return ans;
    }
};