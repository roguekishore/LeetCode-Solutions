class Solution {
public:
    ListNode* mergeSort(ListNode* leftHead,ListNode* rightHead) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(leftHead && rightHead) {
            if(leftHead->val <= rightHead->val) {
                curr->next = leftHead;
                leftHead = leftHead->next;
            } else {
                curr->next = rightHead;
                rightHead = rightHead->next;
            }
            curr = curr->next;
        }

        curr->next = leftHead ? leftHead : rightHead;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow;
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return mergeSort(left, right);
    }
};