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
    bool hasCycle(ListNode* head) {
        ListNode *curr1 = head;
        ListNode *curr2 = head;

        while(curr2!=NULL && curr2->next!=NULL) {
            curr1 = curr1->next;
            curr2 = curr2->next->next;

            if(curr1 == curr2)
            return true;
        }

        return false;
    }
};
