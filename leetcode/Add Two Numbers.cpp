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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        int carry = 0, sum;
        ListNode *tmp = NULL, *head = l1;
        
        while(l1 || l2) {
            if (l1 && l2) {
                sum = l1 -> val + l2 -> val + carry;
                l1 -> val = sum % 10;
                carry = sum / 10;
                tmp = l1;
                l1 = l1 -> next;
                l2 = l2 -> next;
            } else if (l1) {
                sum = l1 -> val + carry;
                l1 -> val = sum % 10;
                carry = sum / 10;
                tmp = l1;
                l1 = l1 -> next;
            } else {
                tmp -> next = l2;
                l1 = l2;
                l2 = NULL;
            }
        }
        if (carry) {
            ListNode *node = new (ListNode);
            node -> val = carry;
            node -> next = NULL;
            tmp -> next = node;
        }
        return head;
    }
};
