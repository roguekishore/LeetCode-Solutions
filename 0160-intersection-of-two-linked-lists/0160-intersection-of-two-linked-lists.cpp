class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_map<ListNode*, int> map;
        // while(headA != nullptr) {
        //     map[headA]++;
        //     headA = headA->next;
        // }
        // while(headB != nullptr) {
        //     if(map[headB] > 0) {
        //         return headB;
        //     }
        //     headB = headB->next;
        // }

        ListNode* node1 = headA;
        ListNode* node2 = headB;
        while(node1 != node2) {
            node1 = node1 ? node1->next : headB;
            node2 = node2 ? node2->next : headA;
        }

        return node2;
    }
};