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
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        vector<int> c;
        
        int mini = INT_MAX;
        
        int i = 1;
        
        while(head && head->next && head->next->next)
        {
            ListNode* f = head;
            ListNode* s = head->next;
            ListNode* t = head->next->next;
            
            if((s->val < f->val && s->val < t->val) || (s->val > f->val && s->val > t->val))
            {
                if(c.size() >= 1)
                    mini = min(mini, i - c.back());
                    
                c.push_back(i);
            }
            
            i++;
            head = head->next;
        }
        
        if(c.size() >= 2)
            return {mini, c.back() - c[0]};
        
        return {-1,-1};
        
    }
};