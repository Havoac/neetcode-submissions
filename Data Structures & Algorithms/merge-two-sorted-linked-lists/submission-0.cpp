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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
        return list2;

        if(list2 == NULL)
        return list1;

        ListNode *head = NULL, *curr = NULL, *curr1 = list1, *curr2 = list2;

        while(curr1!=NULL && curr2!=NULL) {
            if(curr1->val <= curr2->val) {
                if(head == NULL) {
                    head = curr1;
                    curr = curr1;
                }
                else {
                    curr->next = curr1;
                    curr = curr1;
                }

                curr1 =  curr1->next;
            }
            else {
                if(head == NULL) {
                    head = curr2;
                    curr = curr2;
                }
                else {
                    curr->next = curr2;
                    curr = curr2;
                }

                curr2 =  curr2->next;
            }
        }

        if(curr1 != NULL) {
            curr->next = curr1;
        }

        if(curr2 != NULL) {
            curr->next = curr2;
        }

        return head;
    }
};
