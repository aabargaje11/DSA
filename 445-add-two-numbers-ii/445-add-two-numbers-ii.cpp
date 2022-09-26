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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head=NULL, *temp = head;
        
        ListNode *temp1=l1, *temp2=l2;
        stack<int> s1,s2;
        
        while(temp1){
            s1.push(temp1->val);
            temp1=temp1->next;
        }
        
        while(temp2){
            s2.push(temp2->val);
            temp2=temp2->next;
        }
        
        int carry = 0;
        
        while(!s1.empty() && !s2.empty()){
            int a = s1.top();
            int b = s2.top();
            
            s1.pop();
            s2.pop();
            
            int sum = a+b+carry;
            
            carry=sum/10;
            sum = sum%10;
            
            ListNode *newNode = new ListNode(sum);
            newNode->next = head;
            head = newNode;
        }
        
        while(!s1.empty()){
            int a= s1.top();
            int sum = a+carry;
            s1.pop();
            
            
            carry=sum/10;
            sum = sum%10; 
            
            ListNode *newNode = new ListNode(sum);
            newNode->next = head;
            head = newNode;
        }
        
        while(!s2.empty()){
            int a= s2.top();
            int sum = a+carry;
            s2.pop();
            
            carry=sum/10;
            sum = sum%10;
            
            ListNode *newNode = new ListNode(sum);
            newNode->next = head;
            head = newNode;
        }
        
        if(carry){
            ListNode *newNode = new ListNode(1);
            newNode->next = head;
            head = newNode;
        }
        
        return head;
    }
};