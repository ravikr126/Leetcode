/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //base case
        if(!head) return NULL;

        //i have to copy the ll into new list
        Node* curr= head;
        while(curr){
            Node* copy= new Node(curr->val);
            copy->next= curr->next;
            curr->next= copy;
            curr= copy->next;
        }
    

    // step 2 copy the randpm pointer

        curr= head;
        while(curr){
            if(curr->random){
                curr->next->random= curr->random->next;
            }
                curr= curr->next->next;
        }

    // step 3 seperate the list

   Node* dummy= new Node(0);
   Node* copyCurr= dummy;
    curr=head;
   while(curr){
    copyCurr->next= curr->next;
    curr->next= curr->next->next;
    copyCurr= copyCurr->next;
    curr= curr->next;
   }

   return dummy->next;

    }
};