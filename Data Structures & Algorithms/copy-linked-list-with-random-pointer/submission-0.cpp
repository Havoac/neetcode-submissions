/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> real_Copy_NodePointers;
        Node *newHead = NULL, *curr = head, *newCurr = NULL;

        while(curr != NULL) {
            if(newHead == NULL) {
                newHead = new Node(curr->val);
                newCurr = newHead;

                real_Copy_NodePointers[curr] = newCurr;
            }
            else {
                newCurr->next = new Node(curr->val);
                newCurr = newCurr->next;

                real_Copy_NodePointers[curr] = newCurr;
            }

            curr = curr->next;
        }

        curr = head;
        newCurr = newHead;

        while(curr != NULL) {
            newCurr->random = real_Copy_NodePointers[curr->random];
            
            curr = curr->next;
            newCurr = newCurr->next;
        }


        return newHead;
    }
};
