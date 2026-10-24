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
    int ComputeTotalNodesCount(ListNode *head) {
        ListNode *curr = head;
        int count = 0;

        while(curr != NULL) {
            curr = curr->next;
            count++;
        }

        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalNodes = ComputeTotalNodesCount(head);

        if(n == totalNodes) {
            head = head->next;
            return head;
        }

        int traversalNeeded = totalNodes-n-1;

        ListNode *curr = head;

        while(curr != NULL && curr->next!=NULL && traversalNeeded>0) {
            curr = curr->next;
            traversalNeeded--;
        }

        if(curr != NULL) {
            if(curr->next != NULL)
                curr->next = curr->next->next;
        }

        return head;
    }
};
