class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while( fast && fast->next ) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                break;
            }
        }
        if(!fast || !fast->next) {
            return NULL;
        }
        slow = head;
        while(true) {
            if(slow==fast) {
                return slow;
            }
            slow = slow->next;
            fast = fast->next;
        }

        return NULL;


        // unordered_set<ListNode*> map;

        // while( head!=NULL ) {
        //     if(map.find(head) != map.end()) {
        //         return head;
        //     }
        //     map.insert(head);
        //     head = head->next;
        // }

        return NULL;
    }
};