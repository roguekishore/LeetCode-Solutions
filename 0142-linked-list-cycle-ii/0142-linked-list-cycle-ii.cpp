/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // ListNode* slow = head;
        // ListNode* fast = head;

        // while( fast!=NULL && fast->next!=NULL ) {
        //     slow = slow->next;
        //     fast = fast->next->next;

        //     if(slow == fast) {
        //         cout<<slow->val;
        //         return slow->next;
        //     }
        // }

        map<ListNode*, int> map;
        ListNode* temp = head;
        while( temp!=NULL ) {
            if(map[temp] > 1) {
                return temp;
            }
            map[temp]++;
            temp = temp->next;
        }

        return NULL;
    }
};