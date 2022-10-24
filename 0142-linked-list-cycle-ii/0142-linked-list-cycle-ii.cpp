/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* res=head;
        while(fast &&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) 
            {
                while(slow!=res)
                {
                    slow=slow->next;
                    res=res->next;
                }
                return res;
            }
        }
        return NULL;
    }
};