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
    ListNode *Reverse(ListNode *head) {
        if(head == NULL)
        return NULL;

        ListNode *prev = NULL, *curr = head, *next = head->next;

        while(curr != NULL) {
            curr->next = prev;
            prev = curr;
            curr = next;

            if(next != NULL)
            next = next->next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;

        ListNode *newHead = NULL, *curr = NULL;
        int rem = 0;

        while(curr1 != NULL && curr2 != NULL) {
            int val = curr1->val + curr2->val + rem;
            rem = val/10;
            val = val%10;

            if(newHead == NULL) {
                newHead = new ListNode(val);
                curr = newHead;
            }
            else {
                curr->next = new ListNode(val);
                curr = curr->next;
            }

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while(curr1 != NULL) {
            int val = curr1->val + rem;
            rem = val/10;
            val = val%10;

            curr->next = new ListNode(val);

            curr = curr->next;
            curr1 = curr1->next;
        }

        while(curr2 != NULL) {
            int val = curr2->val + rem;
            rem = val/10;
            val = val%10;

            curr->next = new ListNode(val);
            
            curr = curr->next;
            curr2 = curr2->next;
        }

        if(rem != 0)
        curr->next = new ListNode(rem);

        return newHead;
    }
};
