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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();

        if(size == 0)
        return NULL;

        if(size == 1)
        return lists[0];

        vector<ListNode*> allCurrentNodes(size, NULL);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(int i=0 ; i<size ; i++) {
            if(lists[i] != NULL) {
                allCurrentNodes[i] = lists[i];
                minHeap.push({lists[i]->val, i});
            }
        }

        ListNode *head = NULL, *curr = NULL;

        while(minHeap.size() > 0) {
            pair<int, int> itr = minHeap.top();
            minHeap.pop();

            if(head == NULL) {
                head = new ListNode(itr.first);
                curr = head;

                if(allCurrentNodes[itr.second] != NULL) {
                    allCurrentNodes[itr.second] = allCurrentNodes[itr.second]->next;

                    if(allCurrentNodes[itr.second] != NULL)
                        minHeap.push({allCurrentNodes[itr.second]->val, itr.second});
                }
            }
            else {
                curr->next = new ListNode(itr.first);
                curr = curr->next;

                if(allCurrentNodes[itr.second] != NULL) {
                    allCurrentNodes[itr.second] = allCurrentNodes[itr.second]->next;

                    if(allCurrentNodes[itr.second] != NULL)
                        minHeap.push({allCurrentNodes[itr.second]->val, itr.second});
                }
            }
        }

        return head;
    }
};
