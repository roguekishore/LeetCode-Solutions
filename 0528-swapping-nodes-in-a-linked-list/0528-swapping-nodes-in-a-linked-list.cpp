class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* nodeA = head;
        ListNode* nodeB = head;
        for(int i=0 ; i<k-1 ; i++){
            nodeA = nodeA->next;
        }
        ListNode* temp = nodeA;
        while(temp->next) {
            temp = temp->next;
            nodeB = nodeB->next;
        }
        swap(nodeA->val, nodeB->val);
        return head;
    }
};