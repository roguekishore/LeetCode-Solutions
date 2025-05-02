class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if( head==NULL || head->next==nullptr ) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};