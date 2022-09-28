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
        ListNode temp(0, head);
        ListNode * right = head, * left = &temp;
        while (n--)
            right = right->next;
        while (right)
            right = right->next, left = left->next;
        left->next = left->next->next;
        return temp.next;
    }
};