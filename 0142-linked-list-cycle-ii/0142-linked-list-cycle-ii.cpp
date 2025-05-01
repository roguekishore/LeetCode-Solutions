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

        unordered_set<ListNode*> map;

        while( head!=NULL ) {
            if(map.find(head) != map.end()) {
                return head;
            }
            map.insert(head);
            head = head->next;
        }

        return NULL;
    }
};