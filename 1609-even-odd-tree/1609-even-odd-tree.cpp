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
    bool isEvenOddTree(TreeNode* root) {
     
        
        queue<TreeNode*> q;
        // cout<<"Hello"<<endl;
        if(!root) return true;
        
        q.push(root);
        int lvl = -1;
        
        while(!q.empty()){
            lvl++;
            
            int len = q.size() - 1;
            int top = q.front()->val;
            if((top+lvl)%2 == 0) return false; 
            
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
            
            while(len!=0){
                // cout<<q.front()->val<<" "<<top<<endl;
                if((q.front()->val+lvl)%2 == 0) return false;
                    
                // Even - odd val - increasing.
                if(lvl%2 == 0){
                    int front = q.front()->val;
                    if(top >= front) return false;
                    top = front;
                }
                else{
                    int front = q.front()->val;
                    if(top <= front) return false;
                    top = front;
                }
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
                len--;
            }    
            
        }

        return true;
    }
};