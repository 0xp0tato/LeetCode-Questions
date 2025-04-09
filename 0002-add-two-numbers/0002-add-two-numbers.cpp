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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(!l1)
            return l2;
        
        if(!l2)
            return l1;
        
        int carry = 0;
        
        int flag = 0;
        ListNode* head = NULL;
        ListNode* i = NULL;
        
        while(l1 && l2)
        {
            int num = l1->val + l2->val + carry;
            carry = 0;
            
            if(num > 9)
                num = num % 10, carry = 1;
            
            if(i)
            {
                i->next = new ListNode(num);
                i=i->next;
            }
            
            else
            {
                i = new ListNode(num);
                head = i;
            }
            
            l1=l1->next;
            l2=l2->next;
            
        }
        
        while(l1)
        {
            int num = l1->val + carry;
            carry = 0;
            
            if(num > 9)
                num = num % 10, carry = 1;
            
            i->next = new ListNode(num);
            i=i->next;
            
            l1 = l1->next;
        }
        
        while(l2)
        {
            int num = l2->val + carry;
            carry = 0;
            
            if(num > 9)
                num = num % 10, carry = 1;
            
            i->next = new ListNode(num);
            i=i->next;
            
            l2 = l2->next;
        }
        
        if(carry)
            i->next = new ListNode(1);
        
        return head;
    }
};