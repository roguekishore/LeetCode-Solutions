class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        ListNode* nodeA = nullptr;
        ListNode* nodeB = nullptr;
        while(temp) {
            if(count == k-1) {
                nodeA = temp;
            }
            count++;
            temp = temp->next;
        }
        temp = head;
        while(temp) {
            if(count == k) {
                nodeB = temp;
                break;
            }
            count--;
            temp = temp->next;
        }
        swap(nodeA->val, nodeB->val);
        return head;
    }
};