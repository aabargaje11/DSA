/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(ListNode* head,ListNode* h, TreeNode* root, bool t){
        if(!head) return true;
        if(!root) return false;
        if(head->val == root->val){
            if(solve(head->next ,h, root->left, true) or solve(head->next ,h, root->right, true) ) return true;
        }
        if (!t) return solve(h ,h, root->left, false) or solve(h ,h, root->right, false);
        return false;

    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(head, head, root, false);
        

    }
};