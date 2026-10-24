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
    int TotalNodesCount(ListNode *head) {
        int count = 0;

        ListNode *curr = head;

        while(curr != NULL)
        {
            curr = curr->next;
            count++;
        }

        return count;
    }

    ListNode *Reverse(ListNode *head) {
        ListNode *prev = NULL, *curr = head;

        while(curr != NULL) {
            ListNode *next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = TotalNodesCount(head);
        ListNode *prev = NULL, *newHead = NULL, *curr = head;

        for(int i=0 ; i<(count/k) ; i++) {
            ListNode *startingNode = curr;

            for(int j=0 ; j<k-1 ; j++)
                curr = curr->next;

            ListNode *next = curr->next;

            curr->next = NULL;

            ListNode *rev = Reverse(startingNode);

            if(prev == NULL)
                newHead = rev;
            else
                prev->next = rev;

            for(int j=0 ; j<k-1 ; j++)
                rev = rev->next;

            prev = rev;
            rev->next = next;

            curr = next;
        }

        return newHead;
    }
};
