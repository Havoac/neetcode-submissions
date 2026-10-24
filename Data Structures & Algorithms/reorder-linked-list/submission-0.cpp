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
        ListNode *prev = NULL;
        ListNode *curr = head;
        
        while(curr != NULL) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    int Count(ListNode *head) {
        ListNode *curr = head;
        int count = 0;

        while(curr != NULL) {
            count++;
            curr = curr->next;
        }

        return count;
    }

    void reorderList(ListNode* head) {
        int totalNodes = Count(head);
        int halfWay = totalNodes/2;

        ListNode *curr2 = head;

        while(halfWay>1) {
            // cout<<curr2->val<<" ";
            curr2 = curr2->next;
            halfWay--;
        }

        ListNode *next = curr2->next;
        curr2->next = NULL;
        curr2 = next;

        // curr2 = head;

        curr2 = Reverse(curr2);

        ListNode *curr1 = head;
        ListNode *curr = head;

        while(curr1!=NULL && curr2!=NULL) {
            ListNode *next1 = curr1->next;
            ListNode *next2 = curr2->next;
            // cout<<curr1->val<<" "<<curr2->val<<"\n";
            curr1->next = curr2;
            curr2->next = next1;

            curr = curr2;

            curr1 = next1;
            curr2 = next2;
        }

        if(curr2 != NULL)
        curr->next = curr2;
    }
};
