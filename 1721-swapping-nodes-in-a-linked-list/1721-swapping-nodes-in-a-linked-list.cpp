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
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode *kthNode, *kthNodeFromEnd = head, *iter = head;
	while(--k)
		iter = iter -> next;
	kthNode = iter;
	while(iter -> next)
		iter = iter -> next, kthNodeFromEnd = kthNodeFromEnd -> next;
	swap(kthNode -> val, kthNodeFromEnd -> val);
	return head;
        
    }
};