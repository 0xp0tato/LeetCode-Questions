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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(!head)
            return head;
        
        ListNode *left = head;
        ListNode *right = head->next;
        
        while(right)
        {
            if(left->val == right->val)
            {
                ListNode *temp = right;
                
                right = right->next;
                left->next = right;
                
                temp->next = NULL;
            }
            
            else{
                left = left->next;
                right = right->next;
            }
        }
        
        return head;
        
    }
};