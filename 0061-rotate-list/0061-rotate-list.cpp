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

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL ) {
            return NULL;
        }
        int size = 0;
        ListNode* last = head;

        while(last->next != nullptr) {
            size++;
            last = last->next;
        }
        size++;
        k = k % size;
        int counter = size - k - 1;
        ListNode* current = head;
        while( counter > 0 ) {
            current = current -> next;
            counter--;
        }
        last->next = head;
        head = current->next;
        current->next = NULL;
        return head;
    }
};