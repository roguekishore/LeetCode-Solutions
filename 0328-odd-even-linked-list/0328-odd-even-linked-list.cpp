class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }

        if( head->next == NULL ) {
            return head;
        }

        ListNode* odd = head;
        ListNode* start = head->next;
        ListNode* even = head->next;

        while(odd->next!=nullptr && even->next!=nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
            
        }

        odd->next = start;

        return head;
    }
};