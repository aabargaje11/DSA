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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> no;
        unordered_map<int, bool> ccc;
        
        
        for(auto x:descriptions){
            int parent = x[0];
            int child = x[1];
            int lt  = x[2];
            TreeNode* pa, *ch;
            
            if(!ccc[parent]) ccc[parent] = false;
            ccc[child] = true;
            if(no[parent] == NULL){
                pa = new TreeNode(parent);
                no[parent] = pa;
            }
            else{
                pa = no[parent];
            }
            if(no[child] == NULL){
                ch = new TreeNode(child);
                no[child] = ch;
            }
            else{
                ch = no[child];
            }
            
            if(lt){
                pa->left = ch;
            }
            else{
                pa->right = ch;
            }
        }

        unordered_map<int, bool>::iterator itr;
        
        for(itr = ccc.begin(); itr!= ccc.end(); itr++){
            // cout<<itr->first<<" "<<itr->second<<endl;
            if(!itr->second){
                cout<<"Return";
                return no[itr->first];
            } 
        }
        
        return NULL;
    }
};