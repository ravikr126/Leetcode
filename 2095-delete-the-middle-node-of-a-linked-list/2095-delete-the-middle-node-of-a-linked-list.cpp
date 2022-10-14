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
    ListNode* deleteMiddle(ListNode* head) {
           
        if(head -> next == NULL)
            return NULL;
        
        // use slow and fast pointer, slow will move by 1 step and fast will move by 2 steps
        
        ListNode* slow = head;
        
        ListNode* fast = head -> next -> next;
        
        while(fast && fast -> next)
        {
            slow = slow -> next;
            
            fast = fast -> next -> next;
        }
        
        // update slow pointer
        
        slow -> next = slow -> next -> next;
        
        return head;
    }
};