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
    inline int gcd(int x, int y){
        int b=min(__builtin_ctz(x), __builtin_ctz(y));
        if (b>0) return gcd(x>>b, y>>b)<<b;
        int r=x%y;
        return (r==0)?y:gcd(y, r);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head->next) return head;
        int x=head->val, y;
        for(ListNode* prev=head, *ptr=head->next; ptr;ptr=ptr->next){
            int y=ptr->val;
        //    cout<<gcd(x, y)<<"-->";
            ListNode* newNode=new ListNode(gcd(x, y), ptr);
            prev->next=newNode;
            prev=ptr;
        //    if(ptr) cout<<ptr->val<<endl;
            x=y;
        }
        return head;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();