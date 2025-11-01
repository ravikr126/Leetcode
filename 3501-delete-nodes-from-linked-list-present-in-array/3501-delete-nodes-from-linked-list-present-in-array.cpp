class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> hasN=0;
        for(int x: nums) hasN[x]=1;
        ListNode dummy(0, head);
        ListNode* prev=&dummy;
        for(ListNode* curr=head; curr; curr=curr->next){
            if (hasN[curr->val]) 
                prev->next=curr->next;
            else 
                prev=prev->next;
        }
        return dummy.next;
    }
};