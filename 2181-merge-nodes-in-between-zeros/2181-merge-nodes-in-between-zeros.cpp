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
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode* head2 = nullptr;
        ListNode* ptr2 = nullptr;
        
        int sum = 0;
        ListNode* ptr = head->next;
        
        while(ptr)  // Corrected loop condition
        {
            sum += ptr->val;
            
            if(ptr->val == 0)
            {
                // Create new node
                ListNode* temp = new ListNode(sum);  // Allocate new ListNode
                
                if(head2 == nullptr)
                {
                    head2 = temp;  // If head2 is nullptr, assign head2 to the new node
                    ptr2 = temp;   // Initialize ptr2 to point to the new node
                }
                else
                {
                    ptr2->next = temp;  // Link new node to the end of the new list
                    ptr2 = temp;        // Update ptr2 to point to the new last node
                }
                
                sum = 0;  // Reset sum for next sequence
            }
            
            ptr = ptr->next;  // Move to the next node in the original list
        }
        
        return head2;
        
    }
};