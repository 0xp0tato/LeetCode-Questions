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
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode* head1 = head;
        ListNode* head2 = head;
        
        while(head2->next)
        {
            head2 = head2 -> next;
            int gcd = __gcd(head1->val, head2->val);
            
            ListNode* temp = new ListNode(gcd);
            
            head1->next = temp;
            temp->next = head2;
            head1 = head2;
        }
        
        return head;
        
    }
};