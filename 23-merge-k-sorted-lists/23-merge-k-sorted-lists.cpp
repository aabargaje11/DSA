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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(int i=0;i<lists.size();i++){
            ListNode* root = lists[i];
            while(root!= NULL){
                q.push(root->val);
                root = root->next;
            }
            
        }
        ListNode* root = new ListNode();
        if(q.size() > 0)
            root->val = q.top();
        else return NULL;
        ListNode* temp = root;
        
        q.pop();
        while(!q.empty()){
            ListNode* t = new ListNode(q.top());
            q.pop();
            temp->next = t;
            temp = t;
        }
        return root;
        
    }
};