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
    TreeNode* solve(vector<int>& preorder, vector<int>& in, int ps, int pe, int &is, int ie,map<int,int> &inMap){
        if(pe < ps || ie < is) return NULL;
        
        int val = preorder[is];
        TreeNode *root = new TreeNode(val);
        int index = inMap[val];
        is++;
        root->left = solve(preorder, in, ps, index-1, is, ie,inMap);
        // is++;
        root->right = solve(preorder, in, index+1, pe, is, ie,inMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inMap;  //for getting the indexes of the elements in inorder
        int len = preorder.size();
        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]]=i;
        int is = 0;
        return solve(preorder, inorder,0,len-1,is,len-1, inMap);
        
    }
};