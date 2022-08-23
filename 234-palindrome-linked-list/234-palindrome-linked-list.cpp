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
    bool isPalindrome(ListNode* head) {
        string ans="";
		ListNode * t = head;
		if(head==NULL)
			return true;
		while(t!=NULL){
			ans+=to_string(t->val);
			t=t->next;
		}
		string x=ans;
		reverse(x.begin(),x.end());
		return x==ans;
    }
};