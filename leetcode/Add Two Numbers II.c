/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * reverse(struct ListNode *head) {
    struct ListNode *pre = NULL, *curr = head, *next = NULL;
    
    if(head == NULL) {
        return head;
    }
    while(curr) {
        next = curr -> next;
        curr -> next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL;
    int carry = 0;
    
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    while(l1 || l2) {
        short int val = 0;
        if (l1) {
            val = l1 -> val;
        }
        if(l2) {
            val = val + l2 -> val;
        }
            
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
            
        if(tmp == NULL) {
            return NULL;
        }
        
        val = val + carry;
        
        tmp -> val = val % 10;
        tmp -> next = head;
        head = tmp;
        
        carry = val / 10;
        
        if(l1) {
            l1 = l1 -> next;
        }
        
        if(l2) {
            l2 = l2 -> next;
        }
    }
    if(carry) {
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
            
        if(tmp == NULL) {
            return NULL;
        }
        
        tmp -> next = head;
        tmp -> val = carry;
        head = tmp;
    }
    return head;
}
