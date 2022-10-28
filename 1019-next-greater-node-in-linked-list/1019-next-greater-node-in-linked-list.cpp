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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> s;
        vector<int> ans(10000,0);
        
        s.push({head->val,0});
        
        head = head->next;
        int i = 1;
        while(head!= NULL){
            
            while(!s.empty() and s.top().first < head->val){
                ans[s.top().second] = head->val;
                s.pop();
            }
            s.push({head->val,i});
            i++;
            head = head->next;
        }
        
        vector<int> ap(ans.begin(),ans.begin()+i);
        return ap;
        
        
    }
};