class Solution {
public:
    ListNode* reverseLL(ListNode* h) {
        ListNode* prev = nullptr;
        while( h!=nullptr ) {
            ListNode* temp = h->next;
            h->next = prev;
            prev = h;
            h = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=nullptr && fast->next->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp1 = head;
        ListNode* temp2 = reverseLL(slow->next);

        while(temp2!=nullptr) {
            if(temp1->val == temp2->val) {
                temp1= temp1->next;
                temp2 = temp2->next;
            } else {
                return false;
            }
        }

        return true;
    }
};