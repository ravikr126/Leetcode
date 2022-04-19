// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
     if(head == NULL) return NULL;
    
    Node* ans = NULL;
    Node* cur = NULL;
    vector<int> big;
    int freq = 0;
    
    Node* p = head;
    while(p != NULL){
        if(p->data == x) freq++;
        else if(p->data < x) {
            Node *temp = new Node(p->data);
            if(ans == NULL){
                ans = temp;
                cur = temp;
            }
        
            cur->next = temp;
            cur = temp;
            
        }
        else {
            big.push_back(p->data);
        }
        
        p = p->next;
    }
    
    while(freq--) {
        Node* temp = new Node(x);
        if(ans == NULL){
            ans = temp;
            cur = temp;
        }
        cur->next = temp;
        cur = temp;
    }
    
    for(int i = 0; i < big.size(); i++) {
        Node* temp = new Node(big[i]);
        if(ans == NULL){
            ans = temp;
            cur = temp;
        }
        cur->next = temp;
        cur = temp;
    }
    
    return ans;
}