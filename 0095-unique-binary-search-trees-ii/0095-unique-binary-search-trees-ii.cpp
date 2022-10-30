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
    vector<TreeNode*> generateMy(int l, int r){
        vector<TreeNode*> res;
        
        if(l> r){
            res.push_back(nullptr);
            return res;
        }
        
        for(int i=l;i<=r;i++){
            vector<TreeNode*> leftTree = generateMy(l,i-1);
            vector<TreeNode*> rightTree = generateMy(i+1,r);
            
            for(TreeNode* left:leftTree){
                for(TreeNode* right:rightTree){
                    TreeNode* temp = new TreeNode(i);
                    temp->left = left;
                    temp->right = right;
                    res.push_back(temp);
                }
            }
        }
        
        return res;
                
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateMy(1,n);
    }
};