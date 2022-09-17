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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * front = head, *back=head;
        int a=n;
        
        while(a!=0){
            front = front->next;
            a--;
        }        
        if(front == NULL){
            head = head->next;
            return head;
        }        
        while(front->next!=NULL){
            front = front->next;
            back = back->next;
        }

        
        back->next = back->next->next;
        
        return head;
        
    }
};